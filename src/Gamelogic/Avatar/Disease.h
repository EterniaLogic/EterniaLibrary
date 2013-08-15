//-----------------------------------------------------------------------------
//  Copyright (C) 2013 Brent Clancy (EterniaLogic, dreadslicer)
//
//  Distributed under a Reference-only License.  The full license is in
//  the file COPYRIGHT, distributed as part of this software.
//-----------------------------------------------------------------------------

#ifndef Disease_h_
#define Disease_h_

// Type defines the "Cause" of the disease.
enum DISEASE_TYPE {DT_PARASITE, DT_FUNGII, DT_VIRUS, DT_CANCER, DT_TOXIN, DT_RADIATION, DT_DRUG};
enum DISEASE_ATTRIBUTES {DA_CONTAGIOUS, DA_INFECTIOUS, DA_FOODBOURNE, DA_COMMUNICABLE, DA_AIRBOURNE, DA_CURABLE};
enum DISEASE_SYMPTOMS {DS_HEARTATTACK, DS_LUNGFAILURE, DS_KIDNEYFAILURE, DS_NEUROFAILURE, DS_CONVULSIONS,
                        DS_VOMITING, DS_BLINDING, DS_MANIA, DS_CONFUSION, DS_HALLUCINATION, DS_COUGH, DS_ANXIETY,
                        DS_ALEXIA, DS_ATAXIA, DS_HYPERVENTILATION, DS_HYPOVENTILATION, DS_FATIGUE, DS_AKATHISIA,
                        DS_ANOSOGNOSIA, DS_VERTIGO, DS_BLEEDING, DS_PAIN, DS_BLURREDVISION
};

#include "../../Data/LinkedList.hpp"
#include "Avatar.h"

class Disease
{
public:
  Disease();
  
  void tick();
  
private:
  float strain; // Strain ID, applied when researches find a strain
  DISEASE_TYPE type; // type id for disease (parasite, virus, ect)
  LinkedList<DISEASE_ATTRIBUTES>* attributes; // list of attributes of the disease
  LinkedList<DISEASE_SYMPTOMS>* symptoms; // symptoms of the disease
  
};

#endif