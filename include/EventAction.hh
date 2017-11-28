#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"
#include "G4ThreeVector.hh"
#include "G4ios.hh"

//aggiunta
#include "G4VHitsCollection.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"

class RunAction;
class PrimaryGeneratorAction;
class EventActionMessenger;


class EventAction : public G4UserEventAction
{
public:
  EventAction();
  virtual ~EventAction();
  
  virtual void  BeginOfEventAction(const G4Event* event);
  virtual void  EndOfEventAction(const G4Event* event);

private:
  
  const long* seeds;
  G4int Event;
};

#endif

