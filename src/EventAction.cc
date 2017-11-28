#include "EventAction.hh"
#include "G4ThreeVector.hh"
#include "G4UnitsTable.hh"
#include "G4Event.hh"
#include "G4SystemOfUnits.hh"

#include <fstream>

//aggiunta
#include "Analysis.hh"
#include "G4VHitsCollection.hh"
#include "G4HCofThisEvent.hh"
#include "G4RunManager.hh"
#include "G4SDManager.hh"
#include "Randomize.hh"
#include <iomanip>
#include "AnalysisManager.hh"
#include "RunAction.hh"

#include "G4Step.hh"
#include "G4Track.hh"

using namespace std;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::EventAction()
: G4UserEventAction()
{
  //ClearVectors();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::~EventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::BeginOfEventAction(const G4Event* /*event*/)
{
  //ClearVectors();
  //runAct->ClearVectors();
  
  //runAct = G4UserRunAction::Instance();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::EndOfEventAction(const G4Event* event)
{
  
  // Numero evento
   Event = event->GetEventID();
   //G4cout << "Evento " << event_id << G4endl;   // utile per print info 
   
   for(G4int i=0; i<1000; i++){
     if(Event == i*100000) G4cout << Event << G4endl;    // utile per run
   }
   // get analysis manager
   G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

   analysisManager->FillNtupleIColumn(1,0,Event);
   analysisManager->AddNtupleRow();
   
   //runAct->ClearVectors();
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......





