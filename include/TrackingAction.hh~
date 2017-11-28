#ifndef TrackingAction_h
#define TrackingAction_h 1

#include "G4UserTrackingAction.hh" //This class represents actions taken place by the user at the start/end point of processing one track.
#include "globals.hh"


class PrimaryGeneratorAction;
class DetectorConstruction;
class RunAction;
class EventAction;

class TrackingAction : public G4UserTrackingAction
{
public:
  TrackingAction(DetectorConstruction*, RunAction*, EventAction*);
  virtual ~TrackingAction();
  
  //  virtual void PreUserTrackingAction(const G4Track*);
  virtual void PostUserTrackingAction(const G4Track*);

private:
  DetectorConstruction* fDetConstruction;
  RunAction*          fRunAction;  
  EventAction*          fEventAction;  

};

#endif
