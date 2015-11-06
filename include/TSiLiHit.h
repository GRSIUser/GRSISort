#ifndef TSILIHIT_H
#define TSILIHIT_H

/** \addtogroup Detectors
 *  @{
 */

#include <cstdio>
#include <utility>

#include "TFragment.h"
#include "TChannel.h"
#include "TGRSIDetectorHit.h"
#include "TPulseAnalyzer.h"

class TSiLiHit : public TGRSIDetectorHit {
	public:
		TSiLiHit();
		~TSiLiHit();

		void Clear(Option_t *opt="");
		void Print(Option_t *opt="") const;

		Double_t GetLed()       { return fLed;      }
		Short_t  GetSegment()   { return fSegment;  }
		Double_t GetSig2Noise() { return fSig2Noise;}    
		Int_t    GetRing()      { return fRing;     }
		Int_t    GetSector()    { return fSector;   }
		Int_t    GetPreamp()    { return fPreamp;   }
		Double_t GetTimeFit()   { return fTimeFit;  }

		void SetSegment(Short_t seg) {
				fSegment = seg; 
				fRing    = 9-(fSegment/12);
				fSector  = fSegment%12;
				fPreamp  = ((GetSector()/3)*2)+(((GetSector()%3)+GetRing())%2);
		}
		void SetVariables(TFragment &frag) { 
				SetCfd(frag.GetCfd());
				SetCharge(frag.GetCharge());
				SetTimeStamp(frag.GetTimeStamp()); 
				fLed    = frag.GetLed();
		}
		void SetWavefit(TFragment&);

	private:
		Double_t    fLed;
		Short_t  fSegment;
		Short_t  fRing;
		Short_t  fSector;
		Short_t  fPreamp;
		Double_t    fTimeFit;
		Double_t    fSig2Noise;

/// \cond CLASSIMP
		ClassDef(TSiLiHit,6);
/// \endcond
};
/*! @} */
#endif
