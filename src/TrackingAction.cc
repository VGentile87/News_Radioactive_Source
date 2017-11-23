#include "TrackingAction.hh"

#include "DetectorConstruction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "G4ParticleDefinition.hh"
#include "G4DynamicParticle.hh"
#include "G4Step.hh"
#include "G4SystemOfUnits.hh"
#include "G4Track.hh"
#include "G4UnitsTable.hh"
#include "G4VProcess.hh"

TrackingAction::TrackingAction(DetectorConstruction* det,RunAction* run, EventAction* event)
  :G4UserTrackingAction(),fDetConstruction(det),fRunAction(run), fEventAction(event)
{}

TrackingAction::~TrackingAction() 
{}

//void TrackingAction::PreUserTrackingAction(const G4Track* atrack)
//{
  //G4bool first_step=false; // da usare in stepping
  //if(atrack->GetCurrentStepNumber()==1)first_step=true;
//}

void TrackingAction::PostUserTrackingAction(const G4Track* track)
{
  //G4cout << "POST USER TRACKING ACTION!!!!!!!!!!" << G4endl;

  // step information
  //const G4Step* step = track->GetStep();
  //G4double stepl = step->GetStepLength();
  G4int TrackID = track->GetTrackID();
<<<<<<< HEAD
  //G4double  Ekin = track->GetKineticEnergy();
=======
  G4double  Ekin = track->GetKineticEnergy();
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
  G4int ParentID = track->GetParentID();
  //G4int pdg = track->GetParticleDefinition()->GetPDGEncoding();
  // G4int whichEmu=0;
  G4String name = track->GetDefinition()->GetParticleName();
  //G4double gunenergy = fGenAction->fparticleGun->GetParticleEnergy();
  //G4double tracklength= track->GetTrackLength()/(um);
  //G4int charge = track->GetDefinition()->GetPDGCharge();
  //G4StepPoint* prePoint      = step->GetPreStepPoint();
  //G4StepPoint* postPoint     = step->GetPostStepPoint();
  //const G4VProcess *proc = postPoint->GetProcessDefinedStep();
  G4String transportation = "Transportation";
  G4String scintillation = "Scintillation";
  G4String inelastic = "inelastic";
  G4String elastic = "hadElastic";
  G4String nCapture = "nCapture";

  G4String creator = "null";
  if(track->GetCreatorProcess() != 0)
    creator = track->GetCreatorProcess()->GetProcessName();

  if(name=="neutron" && ParentID==0){
    //if(proc->GetProcessName()==elastic) whichEmu = 1;
    //if(proc->GetProcessName()==inelastic) whichEmu = 2;
    //if(proc->GetProcessName()==nCapture) whichEmu = 3;
  }


  // G4cout <<"\n-------> I am executing POST_ UserTrackingAction <---------\n" 
  // 	 <<" stepl = " <<G4BestUnit(stepl,"Length")
  // 	 << " Volume in which the particle is : " 
  // 	 << step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetName()
  // 	 << G4endl;

  //G4int Nsecondaries =0;
  if(TrackID == 1)
    {
      /*     G4cout<< "Primary particle: it is a " 
	    <<track->GetParticleDefinition()->GetParticleName() 
	    << " with a kinetic energy of " << Ekin/MeV << " MeV" 
	    << G4endl;*/

      // fEventAction->GetPrimaryPDG(pdg);
     }

  if(TrackID !=1)
    {
      /*  G4cout<< "Secondary particle: it is a " 
	    << track->GetParticleDefinition()->GetParticleName() 
	    << " with a kinetic energy of " << Ekin/MeV << " MeV; " 
	    << " Parent ID = " << ParentID
	    << G4endl;*/
    
  
      if(ParentID == 1 && creator==inelastic)
	{
<<<<<<< HEAD
	  //G4cout << Ekin << " ";
	  //G4cout << track->GetParticleDefinition()->GetParticleName()<<G4endl;
=======
	  G4cout << Ekin << " ";
	  G4cout << track->GetParticleDefinition()->GetParticleName()<<G4endl;
>>>>>>> 9d5b8f85085057b3eace7d4b633b47f941301264
	  //fEventAction->AddSecondary();
	}
    }
  
  //  G4cout << "Number of 2ry particles = " << Nsecondaries << G4endl;
  
}


