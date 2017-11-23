#include "DetectorConstruction.hh"
#include "DetectorMessenger.hh"
<<<<<<< HEAD
#include "G4Material.hh"
#include "G4NistManager.hh"
=======

#include "G4Material.hh"
#include "G4NistManager.hh"

>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
<<<<<<< HEAD
=======

>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"
<<<<<<< HEAD
=======

>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4SystemOfUnits.hh"
#include "G4RunManager.hh"
#include "G4PhysicalConstants.hh"
#include "G4SubtractionSolid.hh"
#include "G4UnionSolid.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
:G4VUserDetectorConstruction(),
 fDefaultMaterial(0), fCylMaterial(0),
 fSolidWorld(0),fLogicWorld(0),fPhysiWorld(0),
 fDetectorMessenger(0)
{

  // materials
  DefineMaterials();
  
  // create commands for interactive definition of the calorimeter
  fDetectorMessenger = new DetectorMessenger(this);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{ delete fDetectorMessenger;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{
  return ConstructDetector();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::DefineMaterials()
{ 

  //
  // Database Material
  //
  
  G4NistManager* nistManager = G4NistManager::Instance();
  nistManager->SetVerbose(1);
  nistManager->FindOrBuildMaterial("G4_POLYETHYLENE"); // plates 
  nistManager->FindOrBuildMaterial("G4_WATER");   // shielding
  nistManager->FindOrBuildMaterial("G4_POLYSTYRENE");  // base emulsion
  nistManager->FindOrBuildMaterial("G4_Pb");  //  lead
  nistManager->FindOrBuildMaterial("G4_Fe");
  nistManager->FindOrBuildMaterial("G4_Cu");  
  nistManager->FindOrBuildMaterial("G4_PLEXIGLASS");
  nistManager->FindOrBuildMaterial("G4_MYLAR");
<<<<<<< HEAD
  nistManager->FindOrBuildMaterial("G4_AIR");
=======
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264

  //
  // Material Properties
  //
  
  G4double a;  // mass of a mole;
  G4double z;  // z=mean number of protons;  
<<<<<<< HEAD
  G4double density;// opera_density, opera_base_density;
  G4double fractionmass;
  G4String name, symbol; 
  G4int ncomponents, natoms;
  G4int base_ncomponents, abs_ncomponents;
=======
  G4double density, opera_density, opera_base_density;
  G4double fractionmass;
  G4String name, symbol; 
  G4int ncomponents, natoms;
  G4int base_ncomponents;
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264

  //
  // Emulsion Component  
  //
  
  a = 126.9*g/mole;
  G4Element* elI  = new G4Element(name="Iodium", symbol="I", z=53., a);
  
  a = 107.9*g/mole;
  G4Element* elAg  = new G4Element(name="Silver", symbol="Ag", z=47., a);

  a = 79.9*g/mole;
  G4Element* elBr  = new G4Element(name="Bromine", symbol="Br", z=35., a);
  
  a = 32.1*g/mole;
  G4Element* elS  = new G4Element(name="Sulphur", symbol="S", z=16., a);
  
  a = 16.00*g/mole;
  G4Element* elO  = new G4Element(name="Oxygen", symbol="O", z=8., a);

  a = 14.01*g/mole;
  G4Element* elN  = new G4Element(name="Nitrogen", symbol="N", z= 7., a);
  
  a = 12.00*g/mole;
  G4Element* elC  = new G4Element(name="Carbon", symbol="C", z= 6., a);

  a = 1.01*g/mole;
  G4Element* elH  = new G4Element(name="Hydrogen",symbol="H" , z= 1., a);

  //
  // NIT EMULSION MATERIAL
  //
  
  density = 3.43*g/cm3; // NIT Emulsion
  G4Material* Emulsion = new G4Material(name="Emulsion", density, ncomponents=8);

  //
  // Fraction Mass NIT
  //
  
  Emulsion->AddElement(elAg,fractionmass=0.44065);
  Emulsion->AddElement(elBr,fractionmass=0.32190);
  Emulsion->AddElement(elI, fractionmass=0.01875);
  Emulsion->AddElement(elC, fractionmass=0.1012);
  Emulsion->AddElement(elO, fractionmass=0.0741);
  Emulsion->AddElement(elN, fractionmass=0.0268);
  Emulsion->AddElement(elH, fractionmass=0.0163);
  Emulsion->AddElement(elS, fractionmass=0.0003);

<<<<<<< HEAD
  //--------- OTHER MATERIAL---------------------------------------------//
=======
  //// OTHER MATERIAL
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
  a = 39.1*g/mole;
  G4Element* elK  = new G4Element(name="Potassium", symbol="K", z=19., a);

  /// POTASSIUM BROMIDE
  G4double density_KBr = 2.75*g/cm3; // NIT Emulsion
  G4Material* KBr = new G4Material(name="KBr", density_KBr, ncomponents=2);
  KBr->AddElement(elK,fractionmass=0.32855);
  KBr->AddElement(elBr,fractionmass=0.67145);
<<<<<<< HEAD


  //ABS C15H17N ( ABS )
  // -------------
  G4double ABSdensity = 1.045*g/cm3;
  G4Material* ABS = new G4Material(name="ABS", ABSdensity, abs_ncomponents=3);
  ABS->AddElement(elC, 15);
  ABS->AddElement(elH, 17);
  ABS->AddElement(elN, 1);
  
  
  //
  // Space Material
=======
  
  //
  // World Material
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
  //
  
  new G4Material("Galactic", z=1., a=1.01*g/mole,density= universe_mean_density,
		 kStateGas, 2.73*kelvin, 3.e-18*pascal);
 

  //PMMA C5H8O2 ( Acrylic )
  // -------------
  G4double ACRdensity = 1.19*g/cm3;
  G4Material* Acrylic = new G4Material(name="Acrylic", ACRdensity, base_ncomponents=3);
  Acrylic->AddElement(elC, 5);
  Acrylic->AddElement(elH, 8);
  Acrylic->AddElement(elO, 2);
  

  G4Material* Polystyrene = new G4Material("Polystyrene", density= 1.050*g/cm3, ncomponents=2);
  Polystyrene->AddElement(elC, natoms=8); 
  Polystyrene->AddElement(elH, natoms=8);

  // Print materials
  G4cout << *(G4Material::GetMaterialTable()) << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::ConstructDetector()
{

  ///// Physical Parameters /////

  //
  // Get materials
<<<<<<< HEAD
  //    
  G4Material* worldMaterial = G4Material::GetMaterial("G4_AIR");           
  G4Material* emulsionMaterial = G4Material::GetMaterial("Emulsion");
  G4Material* baseMaterial = G4Material::GetMaterial("Acrylic");
  G4Material* boxMaterial = G4Material::GetMaterial("ABS");
  //G4Material* baseMaterial = G4Material::GetMaterial("G4_POLYSTYRENE");
  //G4Material* KBrMaterial = G4Material::GetMaterial("KBr");        
  //G4Material* plateMaterial = G4Material::GetMaterial("G4_WATER");
  //G4Material* plateMaterial = G4Material::GetMaterial("G4_POLYETHYLENE");
  //G4Material* leadMaterial = G4Material::GetMaterial("G4_Pb");
  //G4Material* supportMaterial = G4Material::GetMaterial("G4_Fe");
  //G4Material* coolingMaterial = G4Material::GetMaterial("G4_Cu");
  //G4Material* nitrogen_box_Material = G4Material::GetMaterial("G4_PLEXIGLASS");
  //G4Material* opera_emulsionMaterial = G4Material::GetMaterial("Opera Emulsion");			
  //G4Material* operabaseMaterial = G4Material::GetMaterial("TAC");
  
  

  if ( ! worldMaterial ) {
=======
  //
  G4Material* KBrMaterial = G4Material::GetMaterial("KBr");            
  G4Material* defaultMaterial = G4Material::GetMaterial("Galactic");           
  G4Material* emulsionMaterial = G4Material::GetMaterial("Emulsion");            
  //G4Material* baseMaterial = G4Material::GetMaterial("G4_POLYSTYRENE");
  G4Material* baseMaterial = G4Material::GetMaterial("Acrylic");
  //G4Material* plateMaterial = G4Material::GetMaterial("G4_WATER");
  G4Material* plateMaterial = G4Material::GetMaterial("G4_POLYETHYLENE");
  G4Material* leadMaterial = G4Material::GetMaterial("G4_Pb");
  G4Material* supportMaterial = G4Material::GetMaterial("G4_Fe");
  G4Material* coolingMaterial = G4Material::GetMaterial("G4_Cu");
  G4Material* nitrogen_box_Material = G4Material::GetMaterial("G4_PLEXIGLASS");
  G4Material* opera_emulsionMaterial = G4Material::GetMaterial("Opera Emulsion");			
  G4Material* operabaseMaterial = G4Material::GetMaterial("TAC");
  G4Material* boxMaterial = G4Material::GetMaterial("G4_MYLAR");
  

  if ( ! defaultMaterial ) {
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
    G4ExceptionDescription msg;
    msg << "Cannot retrieve materials already defined."; 
    G4Exception("B4DetectorConstruction::DefineVolumes()",
      "MyCode0001", FatalException, msg);
  }  

 
  /////  Geometrical Parameters /////

  //
  //Dimensioni del mondo
  //
  
  G4double worldSizeX = 5 *m;
  G4double worldSizeY = 5 *m;
  G4double worldSizeZ = 5 *m; 

  //
  // Detector
  //
  
  //G4double baseThickness  = 175*um; // PLASTIC
  G4double baseThickness  = 1*mm;  //PMMA  --- SLIDE GLASS
  G4double layerThickness = 50*um;
<<<<<<< HEAD
  G4double emuSizeX       = 75*mm; //12.0*cm;  
  G4double emuSizeY       = 26.5*mm; //10.0*cm;
=======
  G4double emuSizeX       = 7.5*cm; //12.0*cm;  
  G4double emuSizeY       = 2.5*cm; //10.0*cm;
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
  G4int nFilm             = 1;//45;//150;   //envir //cosmog  
  G4double distance = 0;//5*mm;
  G4double filmThickness   = baseThickness+layerThickness+distance; //*2 se double coated
  G4double detThickness   = filmThickness*nFilm;


<<<<<<< HEAD
  G4double boxX = 76*mm;
  G4double boxY = 56.5*mm;
  G4double boxZ = 15*mm;
  G4double hole1X = 61*mm;
  G4double hole1Y = 26.5*mm;
  G4double hole1Z = 2*mm;
  G4double hole2X = 11.5*mm;
  G4double hole2Y = 23.5*mm;
  G4double hole2Z = 3*mm;
  //G4double box_thickness=0.5*cm;
=======
  G4double boxX = 2.5*cm;
  G4double boxY = 2.5*cm;
  G4double boxZ = 1.5*cm;
  G4double box_thickness=0.5*cm;
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
  
  //     
  // World
  //
  
  G4VSolid* worldS 
    = new G4Box("World", worldSizeX/2, worldSizeY/2, worldSizeZ/2);                      
  G4LogicalVolume* worldLV
<<<<<<< HEAD
    = new G4LogicalVolume(worldS, worldMaterial,"World");
=======
    = new G4LogicalVolume(worldS, defaultMaterial,"World");
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
                                   
  G4VPhysicalVolume* worldPV
    = new G4PVPlacement(0, G4ThreeVector(),worldLV,                         
                 "World", 0, false, 0, fCheckOverlaps); 
  
  //                               
  // Emulsion Detector
  //
  
  G4VSolid* detectorS 
    = new G4Box("Detector", emuSizeX/2, emuSizeY/2, detThickness/2);
                         
  G4LogicalVolume* detectorLV
<<<<<<< HEAD
    = new G4LogicalVolume(detectorS, worldMaterial, "Detector"); 
=======
    = new G4LogicalVolume(detectorS, defaultMaterial, "Detector"); 
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
                                   
  fDetectorPV
    = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), 
			detectorLV, "Detector", worldLV,  
			false, 0, fCheckOverlaps); 
  //                               
  // Emulsion Film
  //
  
  G4VSolid* filmS 
    = new G4Box("Film", emuSizeX/2, emuSizeY/2, filmThickness/2);
  
  G4LogicalVolume* filmLV
<<<<<<< HEAD
    = new G4LogicalVolume(filmS,worldMaterial, "Film");
=======
    = new G4LogicalVolume(filmS,defaultMaterial, "Film");
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
  
  new G4PVReplica("Film", filmLV, detectorLV,
		  kZAxis, nFilm, filmThickness);

  //                               
  // Layers
  //
 
   G4VSolid* emulsionS 
    = new G4Box("Emulsion", emuSizeX/2, emuSizeY/2, layerThickness/2);
                         
  G4LogicalVolume* emulsionLV
    = new G4LogicalVolume(emulsionS, emulsionMaterial, "Emulsion"); 
  
  fEmulsionTopPV 
<<<<<<< HEAD
    = new G4PVPlacement(0, G4ThreeVector(0., 0.,-filmThickness/2 + layerThickness/2),       
=======
    = new G4PVPlacement(0, G4ThreeVector(0., 0.,filmThickness/2 - layerThickness/2),       
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
			emulsionLV, "TopEmulsion", filmLV,
			false, 0, fCheckOverlaps);
  
  //
  // Plastic base
  //
 
  G4VSolid* baseS 
    = new G4Box("Base", emuSizeX/2, emuSizeY/2, baseThickness/2);
  
  G4LogicalVolume* baseLV
    = new G4LogicalVolume(baseS, baseMaterial, "Base"); 
  
  fBasePV
<<<<<<< HEAD
    = new G4PVPlacement(0, G4ThreeVector(0., 0.,-detThickness/2 + layerThickness + baseThickness/2), 
=======
    = new G4PVPlacement(0, G4ThreeVector(0., 0.,detThickness/2 - layerThickness - baseThickness/2), 
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
			baseLV, "Base", filmLV,false, 0, fCheckOverlaps);


  
  //
  // Source container
  //
  
  G4VSolid* boxS_o 
<<<<<<< HEAD
    =new G4Box("box_outer", boxX/2., boxY/2., boxZ/2.);

  G4VSolid* boxS_m
    = new G4Box("box_middle", hole1X/2., hole1Y/2., hole1Z/2.);
  
  G4VSolid* boxS_i 
    = new G4Box("box_inner", hole2X/2., hole2Y/2., hole2Z/2.);

  G4SubtractionSolid* box1 =
    new G4SubtractionSolid("Box1", boxS_o,boxS_m, 0, G4ThreeVector(7.5*mm,0*mm,6.5*mm));

  G4SubtractionSolid* boxS =
    new G4SubtractionSolid("BoxS", box1,boxS_i, 0, G4ThreeVector(1.25*mm,0*mm,4*mm));
  
    
=======
    = new G4Box("box_outer", boxX/2, boxY/2, boxZ/2);

  G4VSolid* boxS_i 
    = new G4Box("box_inner", boxX/2.-box_thickness, boxY/2.-box_thickness, boxZ/2.-box_thickness);

  G4SubtractionSolid* boxS =
    new G4SubtractionSolid("Box_container", boxS_o,boxS_i);
  
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
  G4LogicalVolume* boxLV
    = new G4LogicalVolume(boxS, boxMaterial, "Container_box"); 
  
  fboxPV
<<<<<<< HEAD
    = new G4PVPlacement(0, G4ThreeVector(-14.5*mm, 0.,-6.025*mm), 
			boxLV, "Container_box", worldLV,false, 0, fCheckOverlaps);
=======
    = new G4PVPlacement(0, G4ThreeVector(0., 0.,detThickness/2.+ boxZ/2.), 
			boxLV, "KBr_source", worldLV,false, 0, fCheckOverlaps);
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
  
  

  
   ///// Draw Experimental Setup /////
  
   //                                        
   // Visualization attributes
   //
   
   worldLV->SetVisAttributes (G4VisAttributes::Invisible);
   
   G4VisAttributes* emulsionVisAtt= new G4VisAttributes();
   emulsionVisAtt->SetVisibility(true);
   emulsionVisAtt->SetColour(G4Colour::Yellow());
   //emulsionVisAtt->SetForceSolid(true);
   emulsionLV->SetVisAttributes(emulsionVisAtt);
   
   G4VisAttributes* baseVisAtt= new G4VisAttributes();
   baseVisAtt->SetVisibility(true);
   baseVisAtt->SetColour(G4Colour::White());
   //baseVisAtt->SetForceSolid(true);
   baseLV->SetVisAttributes(baseVisAtt);
   //KBrLV->SetVisAttributes(baseVisAtt);
<<<<<<< HEAD

   G4VisAttributes* boxVisAtt= new G4VisAttributes();
   boxVisAtt->SetVisibility(true);
   boxVisAtt->SetColour(G4Colour::Green());
   //emulsionVisAtt->SetForceSolid(true);
   boxLV->SetVisAttributes(boxVisAtt);
=======
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
   
   return worldPV;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DetectorConstruction::PrintDetectorParameters()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
