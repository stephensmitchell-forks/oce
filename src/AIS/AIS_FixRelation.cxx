// File:	AIS_FixRelation.cdl
// Created:	Tue Dec  5 15:09:04 1996
// Author:	Flore Lantheaume/Odile Olivier
//              <ODL>

#define BUC60915        //GG 05/06/01 Enable to compute the requested arrow size
//                      if any in all dimensions.

#include <Standard_NotImplemented.hxx>

#include <AIS_FixRelation.ixx>

#include <AIS_Shape.hxx>

#include <TopAbs_ShapeEnum.hxx>

#include <SelectMgr_EntityOwner.hxx>
#include <Select3D_SensitiveSegment.hxx>

#include <BRep_Tool.hxx>
#include <BRepAdaptor_Curve.hxx>

#include <TopoDS.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Wire.hxx>
#include <TopExp.hxx>
#include <TopLoc_Location.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_ListIteratorOfListOfShape.hxx>

#include <TColStd_ListIteratorOfListOfTransient.hxx>

#include <Geom_Curve.hxx>
#include <Geom_Line.hxx>
#include <Geom_Circle.hxx>
#include <Geom_Plane.hxx>

#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir.hxx>
#include <gp_Ax1.hxx>
#include <gp_XYZ.hxx>

#include <ElCLib.hxx>
#include <ElSLib.hxx>

#include <Precision.hxx>

#include <Standard_DomainError.hxx>

#include <DsgPrs_FixPresentation.hxx>

#include <AIS.hxx>

static Standard_Boolean InDomain(const Standard_Real fpar,
					const Standard_Real lpar,
					const Standard_Real para) 
{
  if (fpar >= 0.) {
    return ((para >= fpar) && (para <= lpar));
  }
  if (para >= (fpar+2*PI)) return Standard_True;
  if (para <= lpar) return Standard_True;
  return Standard_False;
}

//=======================================================================
//function : Constructor
//purpose  : vertex Fix Relation
//=======================================================================

AIS_FixRelation::AIS_FixRelation(const TopoDS_Shape& aShape, 
				 const Handle(Geom_Plane)& aPlane, 
				 const TopoDS_Wire& aWire)
:AIS_Relation(),
 myWire(aWire),
 haspos(Standard_False)
{
  myFShape = aShape;
  myPlane = aPlane;
  myAutomaticPosition = Standard_True;
  myArrowSize = 5.;
}

//=======================================================================
//function : Constructor
//purpose  : vertex Fix Relation
//=======================================================================

AIS_FixRelation::AIS_FixRelation(const TopoDS_Shape& aShape, 
				 const Handle(Geom_Plane)& aPlane, 
				 const TopoDS_Wire& aWire, 
				 const gp_Pnt& aPosition, 
				 const Standard_Real anArrowSize)
:AIS_Relation(),
 myWire(aWire),
 haspos(Standard_False)
{
  myFShape = aShape;
  myPlane = aPlane;
  myPosition = aPosition;
#ifdef BUC60915
  SetArrowSize( anArrowSize );
#else
  myArrowSize = anArrowSize;
#endif
  myAutomaticPosition = Standard_False;
}


//=======================================================================
//function : Constructor
//purpose  : edge (line or circle) Fix Relation
//=======================================================================

AIS_FixRelation::AIS_FixRelation(const TopoDS_Shape& aShape, 
				 const Handle(Geom_Plane)& aPlane):
haspos(Standard_False)
{
  myFShape = aShape;
  myPlane = aPlane;
  myAutomaticPosition = Standard_True;
  myArrowSize = 5.;
}

//=======================================================================
//function : Constructor
//purpose  : edge (line or circle) Fix Relation
//=======================================================================

AIS_FixRelation::AIS_FixRelation(
	const TopoDS_Shape& aShape, 
	const Handle(Geom_Plane)& aPlane, 
	const gp_Pnt& aPosition, 
	const Standard_Real anArrowSize):
haspos(Standard_False)
{
  myFShape = aShape;
  myPlane = aPlane;
  myPosition = aPosition;
#ifdef BUC60915
  SetArrowSize( anArrowSize );
#else
  myArrowSize = anArrowSize;
#endif
  myAutomaticPosition = Standard_False;
}

//=======================================================================
//function : Wire
//purpose  : 
//=======================================================================

TopoDS_Wire AIS_FixRelation::Wire()
{
  return myWire;
}

//=======================================================================
//function : SetWire
//purpose  : 
//=======================================================================

void AIS_FixRelation::SetWire(const TopoDS_Wire& aWire)
{
  myWire = aWire;
}


//=======================================================================
//function : Compute
//purpose  : 
//=======================================================================

void AIS_FixRelation::Compute(const Handle(PrsMgr_PresentationManager3d)&, 
			      const Handle(Prs3d_Presentation)& aPresentation, 
			      const Standard_Integer)
{
  aPresentation->Clear();

  // Calcul du point de positionnement du symbole et du
  // point d'attache du segment de raccord sur la shape
  gp_Pnt curpos;
  if (myFShape.ShapeType() == TopAbs_VERTEX)
    ComputeVertex(TopoDS::Vertex(myFShape), curpos);
  else if (myFShape.ShapeType() == TopAbs_EDGE)
    ComputeEdge(TopoDS::Edge(myFShape), curpos);

  const gp_Dir& nor = myPlane->Axis().Direction();

  
  // calcul de la presentation
  //definition de la taille du symbole
#ifdef BUC60915
  if( !myArrowSizeIsDefined )
#endif
    myArrowSize = 5.;

    //creation du presentable
  DsgPrs_FixPresentation::Add(aPresentation,
			      myDrawer,
			      myPntAttach,
			      curpos,
			      nor,
			      myArrowSize);
}

//=======================================================================
//function : Compute
//purpose  : to avoid warning
//=======================================================================

void AIS_FixRelation::Compute(const Handle(Prs3d_Projector)& aProjector,
			      const Handle(Prs3d_Presentation)& aPresentation)
{
// Standard_NotImplemented::Raise("AIS_FixRelation::Compute(const Handle(Prs3d_Projector)&,const Handle(Prs3d_Presentation)&)");
 PrsMgr_PresentableObject::Compute( aProjector , aPresentation ) ; 
}

//=======================================================================
//function : Compute
//purpose  : to avoid warning
//=======================================================================

void AIS_FixRelation::Compute(const Handle(PrsMgr_PresentationManager2d)& aPresentationManager2d,
			      const Handle(Graphic2d_GraphicObject)& aGraphicObject,
			      const Standard_Integer anInteger)
{
// Standard_NotImplemented::Raise("AIS_FixRelation::Compute(const Handle(PrsMgr_PresentationManager2d)&,const Handle(Graphic2d_GraphicObject)&,const Standard_Integer)");
 PrsMgr_PresentableObject::Compute( aPresentationManager2d ,aGraphicObject,anInteger) ; 
}

//=======================================================================
//function : Compute
//purpose  : 
//=======================================================================

void AIS_FixRelation::Compute(const Handle_Prs3d_Projector& aProjector,
                              const Handle_Geom_Transformation& aTransformation,
                              const Handle_Prs3d_Presentation& aPresentation)
{
// Standard_NotImplemented::Raise("AIS_FixRelation::Compute(const Handle_Prs3d_Projector&, const Handle_Geom_Transformation&, const Handle_Prs3d_Presentation&)");
 PrsMgr_PresentableObject::Compute( aProjector , aTransformation , aPresentation ) ;
}

//=======================================================================
//function : ComputeSelection
//purpose  : 
//=======================================================================

void AIS_FixRelation::ComputeSelection(const Handle(SelectMgr_Selection)& aSelection, 
				       const Standard_Integer)
{
  Handle(SelectMgr_EntityOwner) own = new SelectMgr_EntityOwner(this,7);

  // creation d'un segment sensible pour le segment de raccordement 
  // de la shape fixe au symbole 'Fix'
  Handle(Select3D_SensitiveSegment) seg;
  seg = new Select3D_SensitiveSegment(own,
				      myPntAttach,
				      myPosition);
  aSelection->Add(seg);
  
  // Creation de la zone sensible du symbole 'Fix'
  gp_Dir norm = myPlane->Axis().Direction();
    
  gp_Vec dirac(myPntAttach,myPosition);
  dirac.Normalize();
  gp_Vec norac = dirac.Crossed(gp_Vec(norm));
  gp_Ax1 ax(myPosition, norm);
  norac.Rotate(ax, PI/8);

  norac*=(myArrowSize/2);
  gp_Pnt P1 = myPosition.Translated(norac);
  gp_Pnt P2 = myPosition.Translated(-norac);
  seg = new Select3D_SensitiveSegment(own,
				      P1,
				      P2);
  aSelection->Add(seg);

  norac*=0.8;
  P1 = myPosition.Translated(norac);
  P2 = myPosition.Translated(-norac);
  dirac*=(myArrowSize/2);
  gp_Pnt PF(P1.XYZ());
  gp_Pnt PL = PF.Translated(dirac);
  PL.Translate(norac);
  seg = new Select3D_SensitiveSegment(own,
				      PF,
				      PL);
  aSelection->Add(seg);


  PF.SetXYZ(P2.XYZ());
  PL = PF.Translated(dirac);
  PL.Translate(norac);
  seg = new Select3D_SensitiveSegment(own,
				      PF,
				      PL);
  aSelection->Add(seg);

  PF.SetXYZ( (P1.XYZ() + P2.XYZ()) /2 );
  PL = PF.Translated(dirac);
  PL.Translate(norac);
  seg = new Select3D_SensitiveSegment(own,
				      PF,
				      PL);
}

//=======================================================================
//function : ComputeVertex
//purpose  : computes myPntAttach and the position of the presentation 
//           when you fix a vertex
//=======================================================================

void AIS_FixRelation::ComputeVertex(const TopoDS_Vertex& /*FixVertex*/,
				    gp_Pnt& curpos)
{
  myPntAttach = BRep_Tool::Pnt(TopoDS::Vertex(myFShape));
  curpos = myPosition;
  if (myAutomaticPosition) {
      gp_Pln pln(myPlane->Pln());
      gp_Dir dir(pln.XAxis().Direction());
      gp_Vec transvec = gp_Vec(dir)*myArrowSize;
      curpos = myPntAttach.Translated(transvec);;
      myPosition = curpos;
      myAutomaticPosition = Standard_True;
  }
}

//=======================================================================
//function : ComputePosition
//purpose  : 
//=======================================================================

gp_Pnt AIS_FixRelation::ComputePosition(const Handle(Geom_Curve)& curv1, 
					const Handle(Geom_Curve)& curv2, 
					const gp_Pnt& firstp1, 
					const gp_Pnt& lastp1, 
					const gp_Pnt& firstp2, 
					const gp_Pnt& lastp2) const 
{
  //---------------------------------------------------------
  // calcul du point d'attache
  //---------------------------------------------------------
  gp_Pnt curpos;

  if (curv1->IsInstance(STANDARD_TYPE(Geom_Circle)) || curv2->IsInstance(STANDARD_TYPE(Geom_Circle))) {    
    Handle(Geom_Circle) gcirc = Handle(Geom_Circle)::DownCast(curv1);
    if (gcirc.IsNull()) gcirc = Handle(Geom_Circle)::DownCast(curv2);
    gp_Dir dir( gcirc->Location().XYZ() + myPntAttach.XYZ() );
    gp_Vec transvec = gp_Vec(dir)*myArrowSize;
    curpos = myPntAttach.Translated(transvec);    
  }

  else {
    gp_Vec vec1(firstp1,lastp1);
    gp_Vec vec2(firstp2,lastp2);
    
    if (!vec1.IsParallel(vec2, Precision::Angular()) ) {
      gp_Dir dir;
      Standard_Real conf =Precision::Confusion();
      if (lastp1.IsEqual(firstp2,conf) || firstp1.IsEqual(lastp2,conf)) dir.SetXYZ(vec1.XYZ() - vec2.XYZ());
      else dir.SetXYZ(vec1.XYZ() + vec2.XYZ());
      gp_Vec transvec = gp_Vec(dir)*myArrowSize;
      curpos = myPntAttach.Translated(transvec);
    }
    else {
      gp_Vec crossvec = vec1.Crossed(vec2);
      vec1.Cross(crossvec);
      gp_Dir dir(vec1);
      curpos = myPntAttach.Translated(gp_Vec(dir)*myArrowSize);
    }
  }

  return curpos;
}

//=======================================================================
//function : ComputePosition
//purpose  : Computes the position of the "fix dimension" when the 
//           fixed object is a vertex which is set at the intersection
//           of two curves.
//           The "dimension" is in the "middle" of the two edges.
//=======================================================================

gp_Pnt AIS_FixRelation::ComputePosition(const Handle(Geom_Curve)& curv, 
					const gp_Pnt& firstp, 
					const gp_Pnt& lastp) const 
{
  //---------------------------------------------------------
  // calcul du point d'attache
  //---------------------------------------------------------
  gp_Pnt curpos;

  if (curv->IsKind(STANDARD_TYPE(Geom_Circle))) {
    
    Handle(Geom_Circle) gcirc = Handle(Geom_Circle)::DownCast(curv);
    gp_Dir dir( gcirc->Location().XYZ() + myPntAttach.XYZ() );
    gp_Vec transvec = gp_Vec(dir)*myArrowSize;
    curpos = myPntAttach.Translated(transvec);
    
  } //if (curv->IsKind(STANDARD_TYPE(Geom_Circle))

  else {
//    gp_Pln pln(Component()->WorkingPlane()->Plane()->GetValue()->Pln());
    gp_Pln pln(myPlane->Pln());
    gp_Dir NormPln = pln.Axis().Direction();
    gp_Vec vec(firstp,lastp);
    vec.Cross( gp_Vec(NormPln));
    vec.Normalize();
    gp_Vec transvec = vec*myArrowSize;
    curpos = myPntAttach.Translated(transvec);
    gp_Ax1 RotAx( myPntAttach, NormPln);
    curpos.Rotate(RotAx, PI/10);
  }

  return curpos;
 }

//=======================================================================
//function : ComputeEdge 
//purpose  : computes myPntAttach and the position of the presentation 
//           when you fix an edge
//=======================================================================

void AIS_FixRelation::ComputeEdge(const TopoDS_Edge& FixEdge, gp_Pnt& curpos)
{
  Handle(Geom_Curve) curEdge;
  gp_Pnt ptbeg,ptend;
  if (!AIS::ComputeGeometry(FixEdge,curEdge,ptbeg,ptend)) return;

  //---------------------------------------------------------
  // calcul du point de positionnement du symbole 'fix'
  //---------------------------------------------------------
        //--> Dans le cas d'une droite
  if (curEdge->IsKind(STANDARD_TYPE(Geom_Line))){
    gp_Lin glin = Handle(Geom_Line)::DownCast(curEdge)->Lin();
    Standard_Real pfirst(ElCLib::Parameter(glin,ptbeg));
    Standard_Real plast(ElCLib::Parameter(glin,ptend));
    ComputeLinePosition(glin, curpos, pfirst, plast);
  }
  
        //--> Dans le cas d'un cercle
  else if (curEdge->IsKind(STANDARD_TYPE(Geom_Circle))) {
    gp_Circ  gcirc = Handle(Geom_Circle)::DownCast(curEdge)->Circ();
    Standard_Real pfirst, plast;
    BRepAdaptor_Curve cu(FixEdge);
    pfirst = cu.FirstParameter();
    plast = cu.LastParameter();
    ComputeCirclePosition(gcirc, curpos, pfirst, plast);
  }
  
  else
    return;
    
}

//=======================================================================
//function : ComputeLinePosition
//purpose  : compute the values of myPntAttach and the position <pos> of
//           the symbol when the fixed edge has a geometric support equal
//           to a line.
//=======================================================================

void AIS_FixRelation::ComputeLinePosition(const gp_Lin& glin, 
					  gp_Pnt& pos, 
					  Standard_Real& pfirst, 
					  Standard_Real& plast)
{
  if (myAutomaticPosition) {
    // le point d'attache est choisi comme milieu du segment
    myPntAttach = ElCLib::Value((pfirst+ plast)/2, glin);
    
    gp_Dir norm = myPlane ->Axis().Direction();
     
    norm.Cross(glin.Position().Direction());
    pos = myPntAttach.Translated(gp_Vec(norm)*myArrowSize);
    myAutomaticPosition = Standard_True;
  } // if (myAutomaticPosition)

  else {
    pos = myPosition;
    Standard_Real linparam = ElCLib::Parameter(glin, pos);

    //cas ou la projection de position se situe entre les 2 vertex
    // de l'edge
    if ( (linparam >= pfirst) && (linparam <= plast) )
      myPntAttach = ElCLib::Value(linparam,glin);
    
    // cas ou la projection de Position est en dehors des limites
    // de l'edge : alors on choisit comme point d'attache le point
    // le plus proche de la projection
    else {
      Standard_Real pOnLin;
      if (linparam > plast)
	pOnLin = plast;
      else
	pOnLin = pfirst;
      myPntAttach = ElCLib::Value(pOnLin,glin);
      gp_Dir norm = myPlane->Axis().Direction();
	
      norm.Cross(glin.Position().Direction());
      gp_Lin lsup(myPntAttach, norm);
      Standard_Real parpos = ElCLib::Parameter(lsup,myPosition);
      pos =  ElCLib::Value(parpos,lsup);
    }

  }
  myPosition = pos;
}

//=======================================================================
//function : ComputeCirclePosition 
//purpose  : compute the values of myPntAttach and the position <pos> of
//           the symbol when the fixed edge has a geometric support equal
//           to a circle. 
//=======================================================================

void AIS_FixRelation::ComputeCirclePosition(
	const gp_Circ& gcirc, 
	gp_Pnt& pos, 
	Standard_Real& pfirst, 
	Standard_Real& plast)
{
  // reajustement des parametres sur le cercle
  if (plast > 2*PI ) {
    Standard_Real nbtours = Floor(plast / (2*PI));
    plast -= nbtours*2*PI;
    pfirst -= nbtours*2*PI;
  }

  if (myAutomaticPosition) {
    // le point d'attache est le "milieu" du segment (par rapport
    // aux parametres des vertex de debut et de fin de l'edge
    
    Standard_Real circparam = (pfirst + plast)/2.;

    if ( !InDomain(pfirst,plast,circparam)) {
      Standard_Real otherpar = circparam + PI;
      if (otherpar > 2*PI) otherpar -= 2*PI;
      circparam = otherpar;
    }

    myPntAttach = ElCLib::Value(circparam, gcirc );

    gp_Vec dir( gcirc.Location().XYZ(), myPntAttach.XYZ() );
    dir.Normalize();
    gp_Vec transvec = dir*myArrowSize;
    pos = myPntAttach.Translated(transvec);
    myPosition = pos;
    myAutomaticPosition = Standard_True;
  } // if (myAutomaticPosition)

  else {
    // cas ou la projection de myPosition est en dehors des 2
    // vertex de l'edge. Dans ce cas on reajuste le parametre
    // dans la portion valable du cercle
    pos = myPosition;

    Standard_Real circparam = ElCLib::Parameter(gcirc, pos);

    if ( !InDomain(pfirst,plast,circparam)) {
      Standard_Real otherpar = circparam + PI;
      if (otherpar > 2*PI) otherpar -= 2*PI;
      circparam = otherpar;
    }
    
    myPntAttach = ElCLib::Value(circparam,gcirc);
  }
}

//=======================================================================
//function : ConnectedEdges
//purpose  : 
//=======================================================================
Standard_Boolean AIS_FixRelation::ConnectedEdges(const TopoDS_Wire& WIRE,
						 const TopoDS_Vertex& V, 
						 TopoDS_Edge& E1, 
						 TopoDS_Edge& E2)
{
  TopTools_IndexedDataMapOfShapeListOfShape  vertexMap;
  TopExp::MapShapesAndAncestors (WIRE,TopAbs_VERTEX,TopAbs_EDGE,vertexMap);
  
  Standard_Boolean found(Standard_False);
  TopoDS_Vertex theVertex;
  for (Standard_Integer i=1; i<=vertexMap.Extent() && !found; i++) {
    if (vertexMap.FindKey(i).IsSame(V)) {
     theVertex = TopoDS::Vertex(vertexMap.FindKey(i));
     found = Standard_True;
   }
  }
  if (!found) {
    E1.Nullify();
    E2.Nullify();
    return Standard_False;
  }

  TopTools_ListIteratorOfListOfShape iterator(vertexMap.FindFromKey(theVertex));
  if (iterator.More()) {
    E1 = TopoDS::Edge(iterator.Value());
    BRepAdaptor_Curve curv(E1);
    iterator.Next();
  }
  else {
    E1.Nullify();
    return Standard_False;
  }

  if (iterator.More()) {
    E2 = TopoDS::Edge(iterator.Value());
    BRepAdaptor_Curve curv(E2);
    iterator.Next();
  }
  else {
    E2.Nullify();
    return Standard_False;
  }
    
  if (iterator.More()) {
    E1.Nullify();
    E2.Nullify();
    return Standard_False;
  }
  return Standard_True;
}