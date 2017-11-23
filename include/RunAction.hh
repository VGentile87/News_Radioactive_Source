#ifndef RunAction_h
#define RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"
#include "G4Event.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class G4Run;
class HistoManager;
//aggiunte
class RunActionMessenger;
class G4Run;
class AnalysisManager;

class RunAction : public G4UserRunAction
{

public:
    RunAction();
    virtual ~RunAction();

    virtual void BeginOfRunAction(const G4Run*);
    virtual void   EndOfRunAction(const G4Run*);
  
  void SetsavehitsFile   (G4String val)        { savehitsFile   = val;};
  void SetsavepmtFile    (G4String val)        { savepmtFile    = val;};
  void SetsavehistFile   (G4String val)        { savehistFile   = val;};
  void Finish();	
  
  G4String GetsavehitsFile()                   {return savehitsFile;};
  G4String GetsavepmtFile()                    {return savepmtFile;};
   
  void EventInfoMC(G4int iPartName, G4int iCreator, G4int iInteraction,G4double iEnergy, G4int iStep, G4int iTrackId, G4int iParentId, G4int iVolume, G4ThreeVector *Mom);
  
  void EventInfoRecoilFirst(G4int iCreator, G4int iInteraction, G4double iEnergyRecoil, G4int iStep, G4int iTrackId, G4int iParentId, G4ThreeVector *Pos, G4ThreeVector *Mom, G4double iTrackLength, G4int iPartName, G4int iVolume, G4double iEnergyDep);      
  
<<<<<<< HEAD
  void EventInfoRecoilLast(G4int iCreator, G4int iInteraction, G4double iEnergyRecoil, G4int iStep, G4int iTrackId, G4int iParentId, G4ThreeVector *Pos,G4ThreeVector *LastPos, G4ThreeVector *Mom, G4double iTrackLength, G4int iPartName, G4int iVolume, G4double iEnergyDep, G4int iCopyNo, G4double iStepLength);      
=======
  void EventInfoRecoilLast(G4int iCreator, G4int iInteraction, G4double iEnergyRecoil, G4int iStep, G4int iTrackId, G4int iParentId, G4ThreeVector *Pos,G4ThreeVector *LastPos, G4ThreeVector *Mom, G4double iTrackLength, G4int iPartName, G4int iVolume, G4double iEnergyDep, G4int iCopyNo);      
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
  

  void ClearVectors();

private:
  G4String savehitsFile;
  G4String savepmtFile;
  G4String savehistFile;
  RunActionMessenger* runMessenger;
  
  G4int Nneu;
  G4int Nrec;
  G4int Nrec2;

<<<<<<< HEAD
  std::vector<G4int>    vMC_CreatorId;
  std::vector<G4int>    vMC_InteractionId;
  std::vector<G4double> vMC_EnergyKin;
  std::vector<G4int>    vMC_StepId;         
  std::vector<G4int>    vMC_TrackId;      
  std::vector<G4int>    vMC_ParentId;     
  std::vector<G4int>    vMC_VolumeId;
  std::vector<G4double> vMC_PX;    
  std::vector<G4double> vMC_PY;    
  std::vector<G4double> vMC_PZ;
  std::vector<G4int>    vMC_PartId;      
  /*
=======
  std::vector<G4int>    vCreator;
  std::vector<G4int>    vInteraction;
  std::vector<G4double> vEnergyKin;
  std::vector<G4int>    vStep;         
  std::vector<G4int>    vTrackId;      
  std::vector<G4int>    vParentId;     
  std::vector<G4int>    vVolume;
  std::vector<G4double> vMC_PX;    
  std::vector<G4double> vMC_PY;    
  std::vector<G4double> vMC_PZ;
  std::vector<G4int>    vPartName;      

>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
  std::vector<G4int>    vCreatorFirst;
  std::vector<G4int>    vInteractionFirst;
  std::vector<G4double> vEnergyKinFirst;
  std::vector<G4double> vEnergyDepFirst; 
  std::vector<G4int>    vStepFirst;   
  std::vector<G4int>    vTrackIdFirst;
  std::vector<G4int>    vParentIdFirst;
  std::vector<G4double> vFirstHitX;     
  std::vector<G4double> vFirstHitY;     
  std::vector<G4double> vFirstHitZ;     
  std::vector<G4double> vFirstHitPX;    
  std::vector<G4double> vFirstHitPY;    
  std::vector<G4double> vFirstHitPZ;    
  std::vector<G4double> vTrackLengthFirst;    
  std::vector<G4int>    vPartNameFirst;      
  std::vector<G4int>    vVolumeFirst;          
<<<<<<< HEAD
  */
  std::vector<G4int>    vCreatorId;
  std::vector<G4int>    vInteractionId;
  std::vector<G4double> vEnergyKin;
  std::vector<G4double> vEnergyDep; 
  std::vector<G4int>    vStepId;   
  std::vector<G4int>    vTrackId;
  std::vector<G4int>    vParentId;
  std::vector<G4double> vPreHitX;     
  std::vector<G4double> vPreHitY;     
  std::vector<G4double> vPreHitZ;
  std::vector<G4double> vPostHitX;     
  std::vector<G4double> vPostHitY;     
  std::vector<G4double> vPostHitZ;     
  std::vector<G4double> vHitPX;    
  std::vector<G4double> vHitPY;    
  std::vector<G4double> vHitPZ;    
  std::vector<G4double> vTrackLength;
  std::vector<G4double> vStepLength;    
  std::vector<G4int>    vPartId;      
  std::vector<G4int>    vVolumeId;
  std::vector<G4int>    vCopyNo;
=======

  std::vector<G4int>    vCreatorLast;
  std::vector<G4int>    vInteractionLast;
  std::vector<G4double> vEnergyKinLast;
  std::vector<G4double> vEnergyDepLast; 
  std::vector<G4int>    vStepLast;   
  std::vector<G4int>    vTrackIdLast;
  std::vector<G4int>    vParentIdLast;
  std::vector<G4double> vLastHitX;     
  std::vector<G4double> vLastHitY;     
  std::vector<G4double> vLastHitZ;
  std::vector<G4double> vPostLastHitX;     
  std::vector<G4double> vPostLastHitY;     
  std::vector<G4double> vPostLastHitZ;     
  std::vector<G4double> vLastHitPX;    
  std::vector<G4double> vLastHitPY;    
  std::vector<G4double> vLastHitPZ;    
  std::vector<G4double> vTrackLengthLast;    
  std::vector<G4int>    vPartNameLast;      
  std::vector<G4int>    vVolumeLast;
  std::vector<G4int>    vCopyNoLast;
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
};


// inline functions
inline void RunAction::ClearVectors(){

<<<<<<< HEAD
  vMC_CreatorId.clear();
  vMC_InteractionId.clear();
  vMC_EnergyKin.clear();
  vMC_StepId.clear();         
  vMC_TrackId.clear();      
  vMC_ParentId.clear();     
  vMC_VolumeId.clear();
  vMC_PX.clear();
  vMC_PY.clear();
  vMC_PZ.clear();
  vMC_PartId.clear();
  /*
=======
  vCreator.clear();
  vInteraction.clear();
  vEnergyKin.clear();
  vStep.clear();         
  vTrackId.clear();      
  vParentId.clear();     
  vVolume.clear();
  vMC_PX.clear();
  vMC_PY.clear();
  vMC_PZ.clear();
  vPartName.clear();

>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
  vCreatorFirst.clear();
  vInteractionFirst.clear();
  vEnergyKinFirst.clear();
  vEnergyDepFirst.clear();
  vStepFirst.clear();
  vTrackIdFirst.clear();
  vParentIdFirst.clear();
  vFirstHitX.clear();
  vFirstHitY.clear();
  vFirstHitZ.clear();
  vFirstHitPX.clear();
  vFirstHitPY.clear();
  vFirstHitPZ.clear();
  vTrackLengthFirst.clear();
  vPartNameFirst.clear();
  vVolumeFirst.clear();
<<<<<<< HEAD
  */
  vCreatorId.clear();
  vInteractionId.clear();
  vEnergyKin.clear();
  vEnergyDep.clear();
  vStepId.clear();
  vTrackId.clear();
  vParentId.clear();
  vPreHitX.clear();
  vPreHitY.clear();
  vPreHitZ.clear();
  vPostHitX.clear();
  vPostHitY.clear();
  vPostHitZ.clear();
  vHitPX.clear();
  vHitPY.clear();
  vHitPZ.clear();
  vTrackLength.clear();
  vStepLength.clear();
  vPartId.clear();
  vVolumeId.clear();
  vCopyNo.clear();
=======

  vCreatorLast.clear();
  vInteractionLast.clear();
  vEnergyKinLast.clear();
  vEnergyDepLast.clear();
  vStepLast.clear();
  vTrackIdLast.clear();
  vParentIdLast.clear();
  vLastHitX.clear();
  vLastHitY.clear();
  vLastHitZ.clear();
  vPostLastHitX.clear();
  vPostLastHitY.clear();
  vPostLastHitZ.clear();
  vLastHitPX.clear();
  vLastHitPY.clear();
  vLastHitPZ.clear();
  vTrackLengthLast.clear();
  vPartNameLast.clear();
  vVolumeLast.clear();
  vCopyNoLast.clear();
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264

}
   
inline void RunAction::EventInfoMC(G4int iPartName, G4int iCreator, G4int iInteraction,G4double iEnergy, G4int iStep, G4int iTrackId, G4int iParentId, G4int iVolume, G4ThreeVector *Mom) {
<<<<<<< HEAD
  vMC_PartId.push_back(iPartName);
  vMC_CreatorId.push_back(iCreator);
  vMC_InteractionId.push_back(iInteraction);
  vMC_EnergyKin.push_back(iEnergy);
  vMC_StepId.push_back(iStep);
  vMC_TrackId.push_back(iTrackId);
  vMC_ParentId.push_back(iParentId);
  vMC_VolumeId.push_back(iVolume);
  vMC_PX.push_back(Mom->x());
  vMC_PY.push_back(Mom->y());
  vMC_PZ.push_back(Mom->z());
  //Nneu ++;
}

/*
=======
  vPartName.push_back(iPartName);
  vCreator.push_back(iCreator);
  vInteraction.push_back(iInteraction);
  vEnergyKin.push_back(iEnergy);
  vStep.push_back(iStep);
  vTrackId.push_back(iTrackId);
  vParentId.push_back(iParentId);
  vVolume.push_back(iVolume);
  vMC_PX.push_back(Mom->x());
  vMC_PY.push_back(Mom->y());
  vMC_PZ.push_back(Mom->z());
  Nneu ++;
}

>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
inline void RunAction::EventInfoRecoilFirst(G4int iCreator, G4int iInteraction, G4double iEnergyRecoil, G4int iStep, G4int iTrackId, G4int iParentId, G4ThreeVector *Pos, G4ThreeVector *Mom, G4double iTrackLength, G4int iPartName, G4int iVolume, G4double iEnergyDep){

  vCreatorFirst.push_back(iCreator);
  vInteractionFirst.push_back(iInteraction);
  vEnergyKinFirst.push_back(iEnergyRecoil);
  vEnergyDepFirst.push_back(iEnergyDep);
  vStepFirst.push_back(iStep);
  vTrackIdFirst.push_back(iTrackId);
  vParentIdFirst.push_back(iParentId);
  vFirstHitX.push_back(Pos->x());
  vFirstHitY.push_back(Pos->y());
  vFirstHitZ.push_back(Pos->z());
  vFirstHitPX.push_back(Mom->x());
  vFirstHitPY.push_back(Mom->y());
  vFirstHitPZ.push_back(Mom->z());
  vTrackLengthFirst.push_back(iTrackLength);
  vPartNameFirst.push_back(iPartName);
  vVolumeFirst.push_back(iVolume);
}
<<<<<<< HEAD
*/

inline void RunAction::EventInfoRecoilLast(G4int iCreator, G4int iInteraction, G4double iEnergyRecoil, G4int iStep, G4int iTrackId, G4int iParentId, G4ThreeVector *PrePos, G4ThreeVector *PostPos, G4ThreeVector *Mom, G4double iTrackLength, G4int iPartName, G4int iVolume, G4double iEnergyDep, G4int iCopyNo, G4double iStepLength){

  vCreatorId.push_back(iCreator);
  vInteractionId.push_back(iInteraction);
  vEnergyKin.push_back(iEnergyRecoil);
  vEnergyDep.push_back(iEnergyDep);
  vStepId.push_back(iStep);
  vTrackId.push_back(iTrackId);
  vParentId.push_back(iParentId);
  vPreHitX.push_back(PrePos->x());
  vPreHitY.push_back(PrePos->y());
  vPreHitZ.push_back(PrePos->z());
  vPostHitX.push_back(PostPos->x());
  vPostHitY.push_back(PostPos->y());
  vPostHitZ.push_back(PostPos->z());
  vHitPX.push_back(Mom->x());
  vHitPY.push_back(Mom->y());
  vHitPZ.push_back(Mom->z());
  vTrackLength.push_back(iTrackLength);
  vStepLength.push_back(iStepLength);
  vPartId.push_back(iPartName);
  vVolumeId.push_back(iVolume);
  vCopyNo.push_back(iCopyNo);
=======

inline void RunAction::EventInfoRecoilLast(G4int iCreator, G4int iInteraction, G4double iEnergyRecoil, G4int iStep, G4int iTrackId, G4int iParentId, G4ThreeVector *Pos, G4ThreeVector *LastPos, G4ThreeVector *Mom, G4double iTrackLength, G4int iPartName, G4int iVolume, G4double iEnergyDep, G4int iCopyNo){

  vCreatorLast.push_back(iCreator);
  vInteractionLast.push_back(iInteraction);
  vEnergyKinLast.push_back(iEnergyRecoil);
  vEnergyDepLast.push_back(iEnergyDep);
  vStepLast.push_back(iStep);
  vTrackIdLast.push_back(iTrackId);
  vParentIdLast.push_back(iParentId);
  vLastHitX.push_back(Pos->x());
  vLastHitY.push_back(Pos->y());
  vLastHitZ.push_back(Pos->z());
  vPostLastHitX.push_back(LastPos->x());
  vPostLastHitY.push_back(LastPos->y());
  vPostLastHitZ.push_back(LastPos->z());
  vLastHitPX.push_back(Mom->x());
  vLastHitPY.push_back(Mom->y());
  vLastHitPZ.push_back(Mom->z());
  vTrackLengthLast.push_back(iTrackLength);
  vPartNameLast.push_back(iPartName);
  vVolumeLast.push_back(iVolume);
  vCopyNoLast.push_back(iCopyNo);
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
  }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

