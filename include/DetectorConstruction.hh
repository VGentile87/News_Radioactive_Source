#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4Box;
class G4Tubs;
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4VSolid;
class G4Material;
class DetectorMessenger;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
  
    DetectorConstruction();
    virtual ~DetectorConstruction();

  public:
  
  virtual G4VPhysicalVolume* Construct();

  const G4VPhysicalVolume* GetEmulsionTopPV() const;
  const G4VPhysicalVolume* GetEmulsionBotPV() const;
  const G4VPhysicalVolume* GetBasePV() const;
  const G4VPhysicalVolume* GetWorldPV() const;
  const G4VPhysicalVolume* GetWaterPV() const;
  const G4VPhysicalVolume* GetAfterShieldingPV() const;
  const G4VPhysicalVolume* GetTopPlatePV() const;
  const G4VPhysicalVolume* GetBotPlatePV() const;
  
  
public:
  
  void PrintDetectorParameters(); // MODIFIED
  
  G4double GetWorldSizeX()         {return fWorldSizeX;}; 
  G4double GetWorldSizeY()         {return fWorldSizeY;}; //mod
  G4double GetWorldSizeZ()         {return fWorldSizeZ;}; //mod
  
  const G4VPhysicalVolume* GetphysiWorld() {return fPhysiWorld;};           
                 
private:
  
  G4Material*        fDefaultMaterial;
  G4double           fWorldSizeY;
  G4double           fWorldSizeZ;
  G4double           fWorldSizeX;

  G4Material*        fCylMaterial;
  G4double           fCylInR;
  G4double           fCylOutR;
  G4double           fCylSizeZ;
  
  G4Box*             fSolidWorld;    //pointer to the solid World 
  G4LogicalVolume*   fLogicWorld;    //pointer to the logical World
  G4VPhysicalVolume* fPhysiWorld;    //pointer to the physical World
  
  DetectorMessenger* fDetectorMessenger;  //pointer to the Messenger
  
  G4VPhysicalVolume*   fDetectorPV; 
  G4VPhysicalVolume*   fEmulsionTopPV; 
  G4VPhysicalVolume*   fEmulsionBotPV; 
  G4VPhysicalVolume*   fBasePV;
  G4VPhysicalVolume*   fBase2PV;
  G4VPhysicalVolume*   fWaterPV;
  G4VPhysicalVolume*   fPolyethilenePV;
  G4VPhysicalVolume*   fBrickPV;
  G4VPhysicalVolume*   fPoly1PV;
  G4VPhysicalVolume*   fPoly2PV;
  G4VPhysicalVolume*   fPoly3PV;
  G4VPhysicalVolume*   fPolyTopPV;
  G4VPhysicalVolume*   fPolyTop2PV;
  G4VPhysicalVolume*   fCooling_boxPV;
  G4VPhysicalVolume*   fNitrogen_boxPV;
  G4VPhysicalVolume*   fAfterShieldingPV; 
  G4VPhysicalVolume*   fplateTopPV;
  G4VPhysicalVolume*   fplateBotPV;
  G4VPhysicalVolume*   fSidesPV;
  G4VPhysicalVolume*   fboxPV;

  
  G4bool  fCheckOverlaps; // option to activate checking of volumes overlaps
  
private:
  
  void DefineMaterials();
  G4VPhysicalVolume* ConstructDetector();     //MODIFIED
};

// inline functions

inline const G4VPhysicalVolume* DetectorConstruction::GetEmulsionTopPV() const { 
  return fEmulsionTopPV; 
}

inline const G4VPhysicalVolume* DetectorConstruction::GetEmulsionBotPV() const { 
  return fEmulsionBotPV; 
}


inline const G4VPhysicalVolume* DetectorConstruction::GetBasePV() const { 
  return fBasePV; 
}

inline const G4VPhysicalVolume* DetectorConstruction::GetWaterPV() const { 
  return fWaterPV; 
}

inline const G4VPhysicalVolume* DetectorConstruction::GetAfterShieldingPV() const { 
  return fAfterShieldingPV; 
}

inline const G4VPhysicalVolume* DetectorConstruction::GetTopPlatePV() const { 
  return fplateTopPV; 
}

inline const G4VPhysicalVolume* DetectorConstruction::GetBotPlatePV() const { 
  return fplateBotPV; 
}
    
     
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


#endif

