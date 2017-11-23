#ifndef SteppingAction_h
#define SteppingAction_h 1

#include "G4UserSteppingAction.hh"    // This class represents actions taken place by the user at each end of stepping.

#include "G4VParticleChange.hh"

class DetectorConstruction;
class EventAction;
class RunAction;
class PrimaryGeneratorAction;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class SteppingAction : public G4UserSteppingAction
{
public:
  //SteppingAction(DetectorConstruction*, EventAction*);
  virtual ~SteppingAction();
  
  SteppingAction(const DetectorConstruction* detectorConstruction,
		 EventAction* eventAction, RunAction* runAction,
		 PrimaryGeneratorAction* primarygeneratorAction
		 );

  virtual void UserSteppingAction(const G4Step*);
    
private:
  const DetectorConstruction* fDetConstruction;
  EventAction*          fEventAction;
  RunAction*          fRunAction;
  PrimaryGeneratorAction* fGenAction;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
