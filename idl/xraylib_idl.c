/*
Copyright (c) 2009, 2010, 2011, Tom Schoonjans
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
    * The names of the contributors may not be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY Tom Schoonjans ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL Tom Schoonjans BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#include <stdio.h>
#include "xraylib.h"
#include <string.h>
#include <stdlib.h>
#include "xrf_cross_sections_aux.h" 

#include "idl_export.h"





extern void IDL_CDECL IDL_XRayInit(int argc, IDL_VPTR argv[]);
extern void IDL_CDECL IDL_SetHardExit(int argc, IDL_VPTR argv[]);
extern void IDL_CDECL IDL_SetExitStatus(int argc, IDL_VPTR argv[]);
extern void IDL_CDECL IDL_SetErrorMessages(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_GetExitStatus_xrl(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_GetErrorMessages(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_AtomicWeight(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_ElementDensity(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_Total(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_Photo(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_Rayl(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_Compt(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_Energy(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_Total(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_Photo(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_Rayl(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_Compt(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_KN(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCS_Thoms(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCS_KN(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCS_Rayl(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCS_Compt(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCSb_Rayl(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCSb_Compt(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCSP_Thoms(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCSP_KN(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCSP_Rayl(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCSP_Compt(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCSPb_Rayl(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCSPb_Compt(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_FF_Rayl(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_SF_Compt(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_MomentTransf(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_LineEnergy(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_FluorYield(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CosKronTransProb(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_EdgeEnergy(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_JumpFactor(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_FluorLine(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_FluorLine(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_RadRate(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_ComptonEnergy(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_Fi(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_Fii(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_Photo_Total(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_Photo_Total(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_Photo_Partial(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_Photo_Partial(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_Total_Kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_Total_Kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_Total_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_Photo_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_Rayl_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_Compt_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_Energy_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_Total_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_Photo_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_Rayl_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_Compt_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCS_Rayl_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCS_Compt_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCSb_Rayl_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCSb_Compt_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCSP_Rayl_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCSP_Compt_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCSPb_Rayl_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_DCSPb_Compt_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_Photo_Total_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_Photo_Total_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_Photo_Partial_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_Photo_Partial_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_Total_Kissel_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_Total_Kissel_CP(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_Refractive_Index_Re(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_Refractive_Index_Im(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_ComptonProfile(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_ComptonProfile_Partial(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_ElectronConfig(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_AtomicNumberToSymbol(int argc, IDL_VPTR argv[]); 
extern IDL_VPTR IDL_CDECL IDL_SymbolToAtomicNumber(int argc, IDL_VPTR argv[]); 
extern IDL_VPTR IDL_CDECL IDL_AtomicLevelWidth(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_AugerRate(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_AugerYield(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_FluorLine_Kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_FluorLine_Kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_FluorLine_Kissel_Cascade(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_FluorLine_Kissel_Cascade(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_FluorLine_Kissel_Nonradiative_Cascade(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_FluorLine_Kissel_Nonradiative_Cascade(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_FluorLine_Kissel_Radiative_Cascade(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_FluorLine_Kissel_Radiative_Cascade(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CS_FluorLine_Kissel_no_Cascade(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_CSb_FluorLine_Kissel_no_Cascade(int argc, IDL_VPTR argv[]);

/*xrf_cross_sections_aux.h functions */
extern IDL_VPTR IDL_CDECL IDL_PL1_pure_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PL1_rad_cascade_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PL1_auger_cascade_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PL1_full_cascade_kissel(int argc, IDL_VPTR argv[]);

extern IDL_VPTR IDL_CDECL IDL_PL2_pure_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PL2_rad_cascade_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PL2_auger_cascade_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PL2_full_cascade_kissel(int argc, IDL_VPTR argv[]);

extern IDL_VPTR IDL_CDECL IDL_PL3_pure_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PL3_rad_cascade_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PL3_auger_cascade_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PL3_full_cascade_kissel(int argc, IDL_VPTR argv[]);

extern IDL_VPTR IDL_CDECL IDL_PM1_pure_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PM1_rad_cascade_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PM1_auger_cascade_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PM1_full_cascade_kissel(int argc, IDL_VPTR argv[]);

extern IDL_VPTR IDL_CDECL IDL_PM2_pure_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PM2_rad_cascade_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PM2_auger_cascade_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PM2_full_cascade_kissel(int argc, IDL_VPTR argv[]);

extern IDL_VPTR IDL_CDECL IDL_PM3_pure_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PM3_rad_cascade_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PM3_auger_cascade_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PM3_full_cascade_kissel(int argc, IDL_VPTR argv[]);

extern IDL_VPTR IDL_CDECL IDL_PM4_pure_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PM4_rad_cascade_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PM4_auger_cascade_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PM4_full_cascade_kissel(int argc, IDL_VPTR argv[]);

extern IDL_VPTR IDL_CDECL IDL_PM5_pure_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PM5_rad_cascade_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PM5_auger_cascade_kissel(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_PM5_full_cascade_kissel(int argc, IDL_VPTR argv[]);



extern IDL_VPTR IDL_CDECL IDL_CompoundParser(int argc, IDL_VPTR argv[]);

extern IDL_VPTR IDL_CDECL IDL_Crystal_GetCrystal(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_Bragg_angle(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_Q_scattering_amplitude(int argc, IDL_VPTR argv[]);
extern void IDL_CDECL IDL_Atomic_Factors(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_Crystal_F_H_StructureFactor(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_Crystal_F_H_StructureFactor_Partial(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_Crystal_UnitCellVolume(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_Crystal_dSpacing(int argc, IDL_VPTR argv[]);


extern IDL_VPTR IDL_CDECL IDL_GetCompoundDataNISTByName(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_GetCompoundDataNISTByIndex(int argc, IDL_VPTR argv[]);
extern IDL_VPTR IDL_CDECL IDL_GetCompoundDataNISTList(int argc, IDL_VPTR argv[]);


static IDL_SYSFUN_DEF2 xrl_functions[] = {
	{{IDL_GetExitStatus_xrl},"GETEXITSTATUS", 0 , 0 , 0 , 0},
	{{IDL_GetErrorMessages},"GETERRORMESSAGES", 0 , 0 , 0 , 0},
	{{IDL_AtomicWeight},"ATOMICWEIGHT", 1 , 1 , 0 , 0},
	{{IDL_ElementDensity},"ELEMENTDENSITY", 1 , 1 , 0 , 0},
	{{IDL_CS_Total},"CS_TOTAL", 2 , 2 , 0 , 0},
	{{IDL_CS_Photo},"CS_PHOTO", 2 , 2 , 0 , 0},
	{{IDL_CS_Rayl},"CS_RAYL", 2 , 2 , 0 , 0},
	{{IDL_CS_Compt},"CS_COMPT", 2 , 2 , 0 , 0},
	{{IDL_CS_Energy},"CS_ENERGY", 2 , 2 , 0 , 0},
	{{IDL_CSb_Total},"CSB_TOTAL", 2 , 2 , 0 , 0},
	{{IDL_CSb_Photo},"CSB_PHOTO", 2 , 2 , 0 , 0},
	{{IDL_CSb_Rayl},"CSB_RAYL", 2 , 2 , 0 , 0},
	{{IDL_CSb_Compt},"CSB_COMPT", 2 , 2 , 0 , 0},
	{{IDL_CS_KN},"CS_KN", 1 , 1 , 0 , 0},
	{{IDL_DCS_Thoms},"DCS_THOMS", 1 , 1 , 0 , 0},
	{{IDL_DCS_KN},"DCS_KN", 2 , 2 , 0 , 0},
	{{IDL_DCS_Rayl},"DCS_RAYL", 3 , 3 , 0 , 0},
	{{IDL_DCS_Compt},"DCS_COMPT", 3 , 3 , 0 , 0},
	{{IDL_DCSb_Rayl},"DCSB_RAYL", 3 , 3 , 0 , 0},
	{{IDL_DCSb_Compt},"DCSB_COMPT", 3 , 3 , 0 , 0},
	{{IDL_DCSP_Thoms},"DCSP_THOMS", 2 , 2 , 0 , 0},
	{{IDL_DCSP_KN},"DCSP_KN", 3 , 3 , 0 , 0},
	{{IDL_DCSP_Rayl},"DCSP_RAYL", 4 , 4 , 0 , 0},
	{{IDL_DCSP_Compt},"DCSP_COMPT", 4 , 4 , 0 , 0},
	{{IDL_DCSPb_Rayl},"DCSPB_RAYL", 4 , 4 , 0 , 0},
	{{IDL_DCSPb_Compt},"DCSPB_COMPT", 4 , 4 , 0 , 0},
	{{IDL_FF_Rayl},"FF_RAYL", 2 , 2 , 0 , 0},
	{{IDL_SF_Compt},"SF_COMPT", 2 , 2 , 0 , 0},
	{{IDL_MomentTransf},"MOMENTTRANSF", 2 , 2 , 0 , 0},
	{{IDL_LineEnergy},"LINEENERGY", 2 , 2 , 0 , 0},
	{{IDL_FluorYield},"FLUORYIELD", 2 , 2 , 0 , 0},
	{{IDL_CosKronTransProb},"COSKRONTRANSPROB", 2 , 2 , 0 , 0},
	{{IDL_EdgeEnergy},"EDGEENERGY", 2 , 2 , 0 , 0},
	{{IDL_JumpFactor},"JUMPFACTOR", 2 , 2 , 0 , 0},
	{{IDL_CS_FluorLine},"CS_FLUORLINE", 3 , 3 , 0 , 0},
	{{IDL_CSb_FluorLine},"CSB_FLUORLINE", 3 , 3 , 0 , 0},
	{{IDL_RadRate},"RADRATE", 2 , 2 , 0 , 0},
	{{IDL_ComptonEnergy},"COMPTONENERGY", 2 , 2 , 0 , 0},
	{{IDL_Fi},"FI", 2 , 2 , 0 , 0},
	{{IDL_Fii},"FII", 2 , 2 , 0 , 0},
	{{IDL_CSb_Photo_Total},"CSB_PHOTO_TOTAL", 2 , 2 , 0 , 0},
	{{IDL_CS_Photo_Total},"CS_PHOTO_TOTAL", 2 , 2 , 0 , 0},
	{{IDL_CSb_Photo_Partial},"CSB_PHOTO_PARTIAL", 3 , 3 , 0 , 0},
	{{IDL_CS_Photo_Partial},"CS_PHOTO_PARTIAL", 3 , 3 , 0 , 0},
	{{IDL_CS_Total_Kissel},"CS_TOTAL_KISSEL", 2 , 2 , 0 , 0},
	{{IDL_CSb_Total_Kissel},"CSB_TOTAL_KISSEL", 2 , 2 , 0 , 0},
	{{IDL_CompoundParser},"COMPOUNDPARSER",1, 1, 0, 0},
	{{IDL_CS_Total_CP},"CS_TOTAL_CP",2,2,0,0},
	{{IDL_CS_Photo_CP},"CS_PHOTO_CP",2,2,0,0},
	{{IDL_CS_Rayl_CP},"CS_RAYL_CP",2,2,0,0},
	{{IDL_CS_Compt_CP},"CS_COMPT_CP",2,2,0,0},
	{{IDL_CS_Energy_CP},"CS_ENERGY_CP", 2 , 2 , 0 , 0},
	{{IDL_CSb_Total_CP},"CSB_TOTAL_CP",2,2,0,0},
	{{IDL_CSb_Photo_CP},"CSB_PHOTO_CP",2,2,0,0},
	{{IDL_CSb_Rayl_CP},"CSB_RAYL_CP",2,2,0,0},
	{{IDL_CSb_Compt_CP},"CSB_COMPT_CP",2,2,0,0},
	{{IDL_DCS_Rayl_CP},"DCS_RAYL_CP",3,3,0,0},
	{{IDL_DCS_Compt_CP},"DCS_COMPT_CP",3,3,0,0},
	{{IDL_DCSb_Rayl_CP},"DCSB_RAYL_CP",3,3,0,0},
	{{IDL_DCSb_Compt_CP},"DCSB_COMPT_CP",3,3,0,0},
	{{IDL_DCSP_Rayl_CP},"DCSP_RAYL_CP",4,4,0,0},
	{{IDL_DCSP_Compt_CP},"DCSP_COMPT_CP",4,4,0,0},
	{{IDL_DCSPb_Rayl_CP},"DCSPB_RAYL_CP",4,4,0,0},
	{{IDL_DCSPb_Compt_CP},"DCSPB_COMPT_CP",4,4,0,0},
	{{IDL_CS_Photo_Total_CP},"CS_PHOTO_TOTAL_CP",2,2,0,0},
	{{IDL_CSb_Photo_Total_CP},"CSB_PHOTO_TOTAL_CP",2,2,0,0},
	{{IDL_CS_Total_Kissel_CP},"CS_TOTAL_KISSEL_CP",2,2,0,0},
	{{IDL_CSb_Total_Kissel_CP},"CSB_TOTAL_KISSEL_CP",2,2,0,0},
	{{IDL_Refractive_Index_Re},"REFRACTIVE_INDEX_RE",3,3,0,0},
	{{IDL_Refractive_Index_Im},"REFRACTIVE_INDEX_IM",3,3,0,0},
	{{IDL_ComptonProfile},"COMPTONPROFILE",2,2,0,0},
	{{IDL_ComptonProfile_Partial},"COMPTONPROFILE_PARTIAL",3,3,0,0},
	{{IDL_ElectronConfig},"ELECTRONCONFIG", 2, 2, 0, 0},
	{{IDL_AtomicNumberToSymbol},"ATOMICNUMBERTOSYMBOL", 1, 1, 0, 0},
	{{IDL_SymbolToAtomicNumber},"SYMBOLTOATOMICNUMBER", 1, 1, 0, 0},
	{{IDL_AtomicLevelWidth},"ATOMICLEVELWIDTH", 2, 2, 0, 0},
	{{IDL_AugerRate},"AUGERRATE", 2, 2, 0, 0},
	{{IDL_AugerYield},"AUGERYIELD", 2, 2, 0, 0},
	{{IDL_CS_FluorLine_Kissel},"CS_FLUORLINE_KISSEL", 3 , 3 , 0 , 0},
	{{IDL_CSb_FluorLine_Kissel},"CSB_FLUORLINE_KISSEL", 3 , 3 , 0 , 0},
	{{IDL_CS_FluorLine_Kissel_Cascade},"CS_FLUORLINE_KISSEL_CASCADE", 3 , 3 , 0 , 0},
	{{IDL_CSb_FluorLine_Kissel_Cascade},"CSB_FLUORLINE_KISSEL_CASCADE", 3 , 3 , 0 , 0},
	{{IDL_CS_FluorLine_Kissel_no_Cascade},"CS_FLUORLINE_KISSEL_NO_CASCADE", 3 , 3 , 0 , 0},
	{{IDL_CSb_FluorLine_Kissel_no_Cascade},"CSB_FLUORLINE_KISSEL_NO_CASCADE", 3 , 3 , 0 , 0},
	{{IDL_CS_FluorLine_Kissel_Nonradiative_Cascade},"CS_FLUORLINE_KISSEL_NONRADIATIVE_CASCADE", 3 , 3 , 0 , 0},
	{{IDL_CSb_FluorLine_Kissel_Nonradiative_Cascade},"CSB_FLUORLINE_KISSEL_NONRADIATIVE_CASCADE", 3 , 3 , 0 , 0},
	{{IDL_CS_FluorLine_Kissel_Radiative_Cascade},"CS_FLUORLINE_KISSEL_RADIATIVE_CASCADE", 3 , 3 , 0 , 0},
	{{IDL_CSb_FluorLine_Kissel_Radiative_Cascade},"CSB_FLUORLINE_KISSEL_RADIATIVE_CASCADE", 3 , 3 , 0 , 0},
	{{IDL_PL1_pure_kissel},"PL1_PURE_KISSEL", 2, 2,  0 , 0},
	{{IDL_PL1_rad_cascade_kissel},"PL1_RAD_CASCADE_KISSEL", 3, 3, 0 , 0},
	{{IDL_PL1_auger_cascade_kissel},"PL1_AUGER_CASCADE_KISSEL", 3, 3, 0 , 0},
	{{IDL_PL1_full_cascade_kissel},"PL1_FULL_CASCADE_KISSEL", 3, 3, 0 , 0},

	{{IDL_PL2_pure_kissel},"PL2_PURE_KISSEL", 3, 3, 0 , 0},
	{{IDL_PL2_rad_cascade_kissel},"PL2_RAD_CASCADE_KISSEL", 4, 4, 0 , 0},
	{{IDL_PL2_auger_cascade_kissel},"PL2_AUGER_CASCADE_KISSEL", 4, 4, 0 , 0},
	{{IDL_PL2_full_cascade_kissel},"PL2_FULL_CASCADE_KISSEL", 4, 4, 0 , 0},

	{{IDL_PL3_pure_kissel},"PL3_PURE_KISSEL", 4, 4, 0 , 0},
	{{IDL_PL3_rad_cascade_kissel},"PL3_RAD_CASCADE_KISSEL", 5, 5, 0 , 0},
	{{IDL_PL3_auger_cascade_kissel},"PL3_AUGER_CASCADE_KISSEL", 5, 5, 0 , 0},
	{{IDL_PL3_full_cascade_kissel},"PL3_FULL_CASCADE_KISSEL", 5, 5, 0 , 0},

	{{IDL_PM1_pure_kissel},"PM1_PURE_KISSEL", 2, 2, 0 , 0},
	{{IDL_PM1_rad_cascade_kissel},"PM1_RAD_CASCADE_KISSEL", 6,6, 0 , 0},
	{{IDL_PM1_auger_cascade_kissel},"PM1_AUGER_CASCADE_KISSEL", 6, 6, 0 , 0},
	{{IDL_PM1_full_cascade_kissel},"PM1_FULL_CASCADE_KISSEL", 6, 6, 0 , 0},

	{{IDL_PM2_pure_kissel},"PM2_PURE_KISSEL", 3 , 3, 0 , 0},
	{{IDL_PM2_rad_cascade_kissel},"PM2_RAD_CASCADE_KISSEL", 7,7, 0 , 0},
	{{IDL_PM2_auger_cascade_kissel},"PM2_AUGER_CASCADE_KISSEL", 7, 7, 0 , 0},
	{{IDL_PM2_full_cascade_kissel},"PM2_FULL_CASCADE_KISSEL",7,7, 0 , 0},

	{{IDL_PM3_pure_kissel},"PM3_PURE_KISSEL", 4, 4, 0 , 0},
	{{IDL_PM3_rad_cascade_kissel},"PM3_RAD_CASCADE_KISSEL", 8, 8, 0 , 0},
	{{IDL_PM3_auger_cascade_kissel},"PM3_AUGER_CASCADE_KISSEL", 8 , 8, 0 , 0},
	{{IDL_PM3_full_cascade_kissel},"PM3_FULL_CASCADE_KISSEL", 8, 8, 0 , 0},

	{{IDL_PM4_pure_kissel},"PM4_PURE_KISSEL", 5, 5, 0 , 0},
	{{IDL_PM4_rad_cascade_kissel},"PM4_RAD_CASCADE_KISSEL", 9, 9, 0 , 0},
	{{IDL_PM4_auger_cascade_kissel},"PM4_AUGER_CASCADE_KISSEL", 9 , 9, 0 , 0},
	{{IDL_PM4_full_cascade_kissel},"PM4_FULL_CASCADE_KISSEL", 9, 9, 0 , 0},

	{{IDL_PM5_pure_kissel},"PM5_PURE_KISSEL", 6, 6, 0 , 0},
	{{IDL_PM5_rad_cascade_kissel},"PM5_RAD_CASCADE_KISSEL", 10, 10, 0 , 0},
	{{IDL_PM5_auger_cascade_kissel},"PM5_AUGER_CASCADE_KISSEL", 10 , 10, 0 , 0},
	{{IDL_PM5_full_cascade_kissel},"PM5_FULL_CASCADE_KISSEL", 10, 10, 0 , 0},

	{{IDL_Crystal_GetCrystal}, "CRYSTAL_GETCRYSTAL", 1, 1, 0, 0},
	{{IDL_Bragg_angle}, "BRAGG_ANGLE", 5, 5, 0, 0},
	{{IDL_Q_scattering_amplitude}, "Q_SCATTERING_AMPLITUDE", 6, 6, 0, 0},
	{{IDL_Crystal_F_H_StructureFactor}, "CRYSTAL_F_H_STRUCTUREFACTOR", 7, 7, 0, 0},
	{{IDL_Crystal_F_H_StructureFactor_Partial}, "CRYSTAL_F_H_STRUCTUREFACTOR_PARTIAL", 10, 10, 0, 0},
	{{IDL_Crystal_UnitCellVolume}, "CRYSTAL_UNITCELLVOLUME", 1, 1, 0, 0},
	{{IDL_Crystal_dSpacing}, "CRYSTAL_DSPACING", 4, 4, 0, 0},
	{{IDL_GetCompoundDataNISTByName}, "GETCOMPOUNDDATANISTBYNAME", 1, 1, 0, 0},
	{{IDL_GetCompoundDataNISTByIndex}, "GETCOMPOUNDDATANISTBYINDEX", 1, 1, 0, 0},
	{{IDL_GetCompoundDataNISTList}, "GETCOMPOUNDDATANISTLIST", 0, 0, 0, 0},

};
static IDL_SYSFUN_DEF2 xrl_procedures[] = {
	{{(IDL_SYSRTN_GENERIC) IDL_XRayInit},"XRAYINIT", 0 , 0 , 0 , 0},
	{{(IDL_SYSRTN_GENERIC) IDL_SetHardExit},"SETHARDEXIT", 1 , 1 , 0 , 0},
	{{(IDL_SYSRTN_GENERIC) IDL_SetExitStatus},"SETEXITSTATUS", 1 , 1 , 0 , 0},
	{{(IDL_SYSRTN_GENERIC) IDL_SetErrorMessages},"SETERRORMESSAGES", 1 , 1 , 0 , 0},
	{{(IDL_SYSRTN_GENERIC) IDL_Atomic_Factors},"ATOMIC_FACTORS", 7 , 7 , 0 , 0},
};


/* Error Handling */
void IDL_CDECL IDL_SetHardExit(int argc, IDL_VPTR argv[])
{
  SetHardExit(IDL_LongScalar(argv[0]));
}

void IDL_CDECL IDL_SetExitStatus(int argc, IDL_VPTR argv[])
{
  SetExitStatus(IDL_LongScalar(argv[0]));
}

IDL_VPTR IDL_CDECL IDL_GetExitStatus_xrl(int argc, IDL_VPTR argv[])
{
  return IDL_GettmpInt((IDL_INT) GetExitStatus());
}

void IDL_CDECL IDL_SetErrorMessages(int argc, IDL_VPTR argv[])
{
  SetErrorMessages(IDL_LongScalar(argv[0]));
}

IDL_VPTR IDL_CDECL IDL_GetErrorMessages(int argc, IDL_VPTR argv[])
{
  return IDL_GettmpInt((IDL_INT) GetErrorMessages());
}



void IDL_CDECL IDL_XRayInit(int argc, IDL_VPTR argv[])
{
  XRayInit();
}

/*macros for the IDL functions */

/*1 argument: 1 int */
#define XRL_1I(name) IDL_VPTR IDL_CDECL IDL_ ## name(int argc, IDL_VPTR argv[])\
{\
  int Z;\
  IDL_VPTR out_var;\
  \
  IDL_ENSURE_SCALAR(argv[0]);\
  IDL_ENSURE_SIMPLE(argv[0]);\
  IDL_EXCLUDE_STRING(argv[0]);\
  Z = IDL_LongScalar(argv[0]);\
  \
  out_var = IDL_Gettmp();\
  out_var->type = IDL_TYP_FLOAT;\
  out_var->value.f = name(Z);\
  \
  return out_var;\
}

/*1 argument: 1 float */
#define XRL_1F(name) IDL_VPTR IDL_CDECL IDL_ ## name(int argc, IDL_VPTR argv[])\
{\
  float E;\
  IDL_VPTR out_var;\
  \
  IDL_ENSURE_SCALAR(argv[0]);\
  IDL_EXCLUDE_STRING(argv[0]);\
  IDL_ENSURE_SIMPLE(argv[0]);\
  E = (float) IDL_DoubleScalar(argv[0]);\
  \
  out_var = IDL_Gettmp();\
  out_var->type = IDL_TYP_FLOAT;\
  out_var->value.f = name(E);\
  \
  return out_var;\
}


/*2 arguments: 1 int, 1 float */
#define XRL_2IF(name) IDL_VPTR IDL_CDECL IDL_ ## name(int argc, IDL_VPTR argv[])\
{\
  int Z;\
  float E;\
  IDL_VPTR out_var;\
  \
  IDL_ENSURE_SCALAR(argv[0]);\
  IDL_EXCLUDE_STRING(argv[0]);\
  IDL_ENSURE_SIMPLE(argv[0]);\
  IDL_ENSURE_SCALAR(argv[1]);\
  IDL_EXCLUDE_STRING(argv[1]);\
  IDL_ENSURE_SIMPLE(argv[1]);\
  Z = IDL_LongScalar(argv[0]);\
  E = (float)IDL_DoubleScalar(argv[1]);\
  \
  out_var = IDL_Gettmp();\
  out_var->type = IDL_TYP_FLOAT;\
  out_var->value.f = name(Z, E);\
  \
  return out_var;\
}

/*2 arguments: 2 int */
#define XRL_2II(name) IDL_VPTR IDL_CDECL IDL_ ## name(int argc, IDL_VPTR argv[])\
{\
  int Z;\
  int Z2;\
  IDL_VPTR out_var;\
  \
  IDL_ENSURE_SCALAR(argv[0]);\
  IDL_EXCLUDE_STRING(argv[0]);\
  IDL_ENSURE_SIMPLE(argv[0]);\
  IDL_ENSURE_SCALAR(argv[1]);\
  IDL_EXCLUDE_STRING(argv[1]);\
  IDL_ENSURE_SIMPLE(argv[1]);\
  Z = IDL_LongScalar(argv[0]);\
  Z2 = IDL_LongScalar(argv[1]);\
  \
  out_var = IDL_Gettmp();\
  out_var->type = IDL_TYP_FLOAT;\
  out_var->value.f = name(Z, Z2);\
  \
  return out_var;\
}

/*2 arguments: 2 float */
#define XRL_2FF(name) IDL_VPTR IDL_CDECL IDL_ ## name(int argc, IDL_VPTR argv[])\
{\
  float Z;\
  float Z2;\
  IDL_VPTR out_var;\
  \
  IDL_ENSURE_SCALAR(argv[0]);\
  IDL_EXCLUDE_STRING(argv[0]);\
  IDL_ENSURE_SIMPLE(argv[0]);\
  IDL_ENSURE_SCALAR(argv[1]);\
  IDL_EXCLUDE_STRING(argv[1]);\
  IDL_ENSURE_SIMPLE(argv[1]);\
  Z = (float) IDL_DoubleScalar(argv[0]);\
  Z2 = (float) IDL_DoubleScalar(argv[1]);\
  \
  out_var = IDL_Gettmp();\
  out_var->type = IDL_TYP_FLOAT;\
  out_var->value.f = name(Z, Z2);\
  \
  return out_var;\
}

/*3 arguments: int, float, float */
#define XRL_3IFF(name) IDL_VPTR IDL_CDECL IDL_ ## name(int argc, IDL_VPTR argv[])\
{\
  int Z;\
  float Z2;\
  float Z3;\
  IDL_VPTR out_var;\
  \
  IDL_ENSURE_SCALAR(argv[0]);\
  IDL_EXCLUDE_STRING(argv[0]);\
  IDL_ENSURE_SIMPLE(argv[0]);\
  IDL_ENSURE_SCALAR(argv[1]);\
  IDL_EXCLUDE_STRING(argv[1]);\
  IDL_ENSURE_SIMPLE(argv[1]);\
  IDL_ENSURE_SCALAR(argv[2]);\
  IDL_EXCLUDE_STRING(argv[2]);\
  IDL_ENSURE_SIMPLE(argv[2]);\
  Z = IDL_LongScalar(argv[0]);\
  Z2 = (float) IDL_DoubleScalar(argv[1]);\
  Z3 = (float) IDL_DoubleScalar(argv[2]);\
  \
  out_var = IDL_Gettmp();\
  out_var->type = IDL_TYP_FLOAT;\
  out_var->value.f = name(Z, Z2, Z3);\
  \
  return out_var;\
}

/*3 arguments: float, float, float */
#define XRL_3FFF(name) IDL_VPTR IDL_CDECL IDL_ ## name(int argc, IDL_VPTR argv[])\
{\
  float Z;\
  float Z2;\
  float Z3;\
  IDL_VPTR out_var;\
  \
  IDL_ENSURE_SCALAR(argv[0]);\
  IDL_EXCLUDE_STRING(argv[0]);\
  IDL_ENSURE_SIMPLE(argv[0]);\
  IDL_ENSURE_SCALAR(argv[1]);\
  IDL_EXCLUDE_STRING(argv[1]);\
  IDL_ENSURE_SIMPLE(argv[1]);\
  IDL_ENSURE_SCALAR(argv[2]);\
  IDL_EXCLUDE_STRING(argv[2]);\
  IDL_ENSURE_SIMPLE(argv[2]);\
  Z = (float) IDL_DoubleScalar(argv[0]);\
  Z2 = (float) IDL_DoubleScalar(argv[1]);\
  Z3 = (float) IDL_DoubleScalar(argv[2]);\
  \
  out_var = IDL_Gettmp();\
  out_var->type = IDL_TYP_FLOAT;\
  out_var->value.f = name(Z, Z2, Z3);\
  \
  return out_var;\
}

/*3 arguments: int, int, float */
#define XRL_3IIF(name) IDL_VPTR IDL_CDECL IDL_ ## name(int argc, IDL_VPTR argv[])\
{\
  int Z;\
  int Z2;\
  float Z3;\
  IDL_VPTR out_var;\
  \
  IDL_ENSURE_SCALAR(argv[0]);\
  IDL_EXCLUDE_STRING(argv[0]);\
  IDL_ENSURE_SIMPLE(argv[0]);\
  IDL_ENSURE_SCALAR(argv[1]);\
  IDL_EXCLUDE_STRING(argv[1]);\
  IDL_ENSURE_SIMPLE(argv[1]);\
  IDL_ENSURE_SCALAR(argv[2]);\
  IDL_EXCLUDE_STRING(argv[2]);\
  IDL_ENSURE_SIMPLE(argv[2]);\
  Z = IDL_LongScalar(argv[0]);\
  Z2 = IDL_LongScalar(argv[1]);\
  Z3 = (float) IDL_DoubleScalar(argv[2]);\
  \
  out_var = IDL_Gettmp();\
  out_var->type = IDL_TYP_FLOAT;\
  out_var->value.f = name(Z, Z2, Z3);\
  \
  return out_var;\
}

/*4 arguments: int, float, float, float */
#define XRL_4IFFF(name) IDL_VPTR IDL_CDECL IDL_ ## name(int argc, IDL_VPTR argv[])\
{\
  int Z;\
  float Z2;\
  float Z3;\
  float Z4;\
  IDL_VPTR out_var;\
  \
  IDL_ENSURE_SCALAR(argv[0]);\
  IDL_EXCLUDE_STRING(argv[0]);\
  IDL_ENSURE_SIMPLE(argv[0]);\
  IDL_ENSURE_SCALAR(argv[1]);\
  IDL_EXCLUDE_STRING(argv[1]);\
  IDL_ENSURE_SIMPLE(argv[1]);\
  IDL_ENSURE_SCALAR(argv[2]);\
  IDL_EXCLUDE_STRING(argv[2]);\
  IDL_ENSURE_SIMPLE(argv[2]);\
  IDL_ENSURE_SCALAR(argv[3]);\
  IDL_EXCLUDE_STRING(argv[3]);\
  IDL_ENSURE_SIMPLE(argv[3]);\
  Z = IDL_LongScalar(argv[0]);\
  Z2 = (float) IDL_DoubleScalar(argv[1]);\
  Z3 = (float) IDL_DoubleScalar(argv[2]);\
  Z4 = (float) IDL_DoubleScalar(argv[3]);\
  \
  out_var = IDL_Gettmp();\
  out_var->type = IDL_TYP_FLOAT;\
  out_var->value.f = name(Z, Z2, Z3, Z4);\
  \
  return out_var;\
}

#define XRL_5IFFFF(name) IDL_VPTR IDL_CDECL IDL_ ## name(int argc, IDL_VPTR argv[])\
{\
  int Z;\
  float Z2;\
  float Z3;\
  float Z4;\
  float Z5;\
  IDL_VPTR out_var;\
  \
  IDL_ENSURE_SCALAR(argv[0]);\
  IDL_EXCLUDE_STRING(argv[0]);\
  IDL_ENSURE_SIMPLE(argv[0]);\
  IDL_ENSURE_SCALAR(argv[1]);\
  IDL_EXCLUDE_STRING(argv[1]);\
  IDL_ENSURE_SIMPLE(argv[1]);\
  IDL_ENSURE_SCALAR(argv[2]);\
  IDL_EXCLUDE_STRING(argv[2]);\
  IDL_ENSURE_SIMPLE(argv[2]);\
  IDL_ENSURE_SCALAR(argv[3]);\
  IDL_EXCLUDE_STRING(argv[3]);\
  IDL_ENSURE_SIMPLE(argv[3]);\
  IDL_ENSURE_SCALAR(argv[4]);\
  IDL_EXCLUDE_STRING(argv[4]);\
  IDL_ENSURE_SIMPLE(argv[4]);\
  Z = IDL_LongScalar(argv[0]);\
  Z2 = (float) IDL_DoubleScalar(argv[1]);\
  Z3 = (float) IDL_DoubleScalar(argv[2]);\
  Z4 = (float) IDL_DoubleScalar(argv[3]);\
  Z5 = (float) IDL_DoubleScalar(argv[4]);\
  \
  out_var = IDL_Gettmp();\
  out_var->type = IDL_TYP_FLOAT;\
  out_var->value.f = name(Z, Z2, Z3, Z4, Z5);\
  \
  return out_var;\
}

#define XRL_6IFFFFF(name) IDL_VPTR IDL_CDECL IDL_ ## name(int argc, IDL_VPTR argv[])\
{\
  int Z;\
  float Z2;\
  float Z3;\
  float Z4;\
  float Z5;\
  float Z6;\
  IDL_VPTR out_var;\
  \
  IDL_ENSURE_SCALAR(argv[0]);\
  IDL_EXCLUDE_STRING(argv[0]);\
  IDL_ENSURE_SIMPLE(argv[0]);\
  IDL_ENSURE_SCALAR(argv[1]);\
  IDL_EXCLUDE_STRING(argv[1]);\
  IDL_ENSURE_SIMPLE(argv[1]);\
  IDL_ENSURE_SCALAR(argv[2]);\
  IDL_EXCLUDE_STRING(argv[2]);\
  IDL_ENSURE_SIMPLE(argv[2]);\
  IDL_ENSURE_SCALAR(argv[3]);\
  IDL_EXCLUDE_STRING(argv[3]);\
  IDL_ENSURE_SIMPLE(argv[3]);\
  IDL_ENSURE_SCALAR(argv[4]);\
  IDL_EXCLUDE_STRING(argv[4]);\
  IDL_ENSURE_SIMPLE(argv[4]);\
  IDL_ENSURE_SCALAR(argv[5]);\
  IDL_EXCLUDE_STRING(argv[5]);\
  IDL_ENSURE_SIMPLE(argv[5]);\
  Z = IDL_LongScalar(argv[0]);\
  Z2 = (float) IDL_DoubleScalar(argv[1]);\
  Z3 = (float) IDL_DoubleScalar(argv[2]);\
  Z4 = (float) IDL_DoubleScalar(argv[3]);\
  Z5 = (float) IDL_DoubleScalar(argv[4]);\
  Z6 = (float) IDL_DoubleScalar(argv[5]);\
  \
  out_var = IDL_Gettmp();\
  out_var->type = IDL_TYP_FLOAT;\
  out_var->value.f = name(Z, Z2, Z3, Z4, Z5, Z6);\
  \
  return out_var;\
}

#define XRL_7IFFFFFF(name) IDL_VPTR IDL_CDECL IDL_ ## name(int argc, IDL_VPTR argv[])\
{\
  int Z;\
  float Z2;\
  float Z3;\
  float Z4;\
  float Z5;\
  float Z6;\
  float Z7;\
  IDL_VPTR out_var;\
  \
  IDL_ENSURE_SCALAR(argv[0]);\
  IDL_EXCLUDE_STRING(argv[0]);\
  IDL_ENSURE_SIMPLE(argv[0]);\
  IDL_ENSURE_SCALAR(argv[1]);\
  IDL_EXCLUDE_STRING(argv[1]);\
  IDL_ENSURE_SIMPLE(argv[1]);\
  IDL_ENSURE_SCALAR(argv[2]);\
  IDL_EXCLUDE_STRING(argv[2]);\
  IDL_ENSURE_SIMPLE(argv[2]);\
  IDL_ENSURE_SCALAR(argv[3]);\
  IDL_EXCLUDE_STRING(argv[3]);\
  IDL_ENSURE_SIMPLE(argv[3]);\
  IDL_ENSURE_SCALAR(argv[4]);\
  IDL_EXCLUDE_STRING(argv[4]);\
  IDL_ENSURE_SIMPLE(argv[4]);\
  IDL_ENSURE_SCALAR(argv[5]);\
  IDL_EXCLUDE_STRING(argv[5]);\
  IDL_ENSURE_SIMPLE(argv[5]);\
  IDL_ENSURE_SCALAR(argv[6]);\
  IDL_EXCLUDE_STRING(argv[6]);\
  IDL_ENSURE_SIMPLE(argv[6]);\
  Z = IDL_LongScalar(argv[0]);\
  Z2 = (float) IDL_DoubleScalar(argv[1]);\
  Z3 = (float) IDL_DoubleScalar(argv[2]);\
  Z4 = (float) IDL_DoubleScalar(argv[3]);\
  Z5 = (float) IDL_DoubleScalar(argv[4]);\
  Z6 = (float) IDL_DoubleScalar(argv[5]);\
  Z7 = (float) IDL_DoubleScalar(argv[6]);\
  \
  out_var = IDL_Gettmp();\
  out_var->type = IDL_TYP_FLOAT;\
  out_var->value.f = name(Z, Z2, Z3, Z4, Z5, Z6, Z7);\
  \
  return out_var;\
}

#define XRL_8IFFFFFFF(name) IDL_VPTR IDL_CDECL IDL_ ## name(int argc, IDL_VPTR argv[])\
{\
  int Z;\
  float Z2;\
  float Z3;\
  float Z4;\
  float Z5;\
  float Z6;\
  float Z7;\
  float Z8;\
  IDL_VPTR out_var;\
  \
  IDL_ENSURE_SCALAR(argv[0]);\
  IDL_EXCLUDE_STRING(argv[0]);\
  IDL_ENSURE_SIMPLE(argv[0]);\
  IDL_ENSURE_SCALAR(argv[1]);\
  IDL_EXCLUDE_STRING(argv[1]);\
  IDL_ENSURE_SIMPLE(argv[1]);\
  IDL_ENSURE_SCALAR(argv[2]);\
  IDL_EXCLUDE_STRING(argv[2]);\
  IDL_ENSURE_SIMPLE(argv[2]);\
  IDL_ENSURE_SCALAR(argv[3]);\
  IDL_EXCLUDE_STRING(argv[3]);\
  IDL_ENSURE_SIMPLE(argv[3]);\
  IDL_ENSURE_SCALAR(argv[4]);\
  IDL_EXCLUDE_STRING(argv[4]);\
  IDL_ENSURE_SIMPLE(argv[4]);\
  IDL_ENSURE_SCALAR(argv[5]);\
  IDL_EXCLUDE_STRING(argv[5]);\
  IDL_ENSURE_SIMPLE(argv[5]);\
  IDL_ENSURE_SCALAR(argv[6]);\
  IDL_EXCLUDE_STRING(argv[6]);\
  IDL_ENSURE_SIMPLE(argv[6]);\
  IDL_ENSURE_SCALAR(argv[7]);\
  IDL_EXCLUDE_STRING(argv[7]);\
  IDL_ENSURE_SIMPLE(argv[7]);\
  Z = IDL_LongScalar(argv[0]);\
  Z2 = (float) IDL_DoubleScalar(argv[1]);\
  Z3 = (float) IDL_DoubleScalar(argv[2]);\
  Z4 = (float) IDL_DoubleScalar(argv[3]);\
  Z5 = (float) IDL_DoubleScalar(argv[4]);\
  Z6 = (float) IDL_DoubleScalar(argv[5]);\
  Z7 = (float) IDL_DoubleScalar(argv[6]);\
  Z8 = (float) IDL_DoubleScalar(argv[7]);\
  \
  out_var = IDL_Gettmp();\
  out_var->type = IDL_TYP_FLOAT;\
  out_var->value.f = name(Z, Z2, Z3, Z4, Z5, Z6, Z7, Z8);\
  \
  return out_var;\
}

#define XRL_9IFFFFFFFF(name) IDL_VPTR IDL_CDECL IDL_ ## name(int argc, IDL_VPTR argv[])\
{\
  int Z;\
  float Z2;\
  float Z3;\
  float Z4;\
  float Z5;\
  float Z6;\
  float Z7;\
  float Z8;\
  float Z9;\
  IDL_VPTR out_var;\
  \
  IDL_ENSURE_SCALAR(argv[0]);\
  IDL_EXCLUDE_STRING(argv[0]);\
  IDL_ENSURE_SIMPLE(argv[0]);\
  IDL_ENSURE_SCALAR(argv[1]);\
  IDL_EXCLUDE_STRING(argv[1]);\
  IDL_ENSURE_SIMPLE(argv[1]);\
  IDL_ENSURE_SCALAR(argv[2]);\
  IDL_EXCLUDE_STRING(argv[2]);\
  IDL_ENSURE_SIMPLE(argv[2]);\
  IDL_ENSURE_SCALAR(argv[3]);\
  IDL_EXCLUDE_STRING(argv[3]);\
  IDL_ENSURE_SIMPLE(argv[3]);\
  IDL_ENSURE_SCALAR(argv[4]);\
  IDL_EXCLUDE_STRING(argv[4]);\
  IDL_ENSURE_SIMPLE(argv[4]);\
  IDL_ENSURE_SCALAR(argv[5]);\
  IDL_EXCLUDE_STRING(argv[5]);\
  IDL_ENSURE_SIMPLE(argv[5]);\
  IDL_ENSURE_SCALAR(argv[6]);\
  IDL_EXCLUDE_STRING(argv[6]);\
  IDL_ENSURE_SIMPLE(argv[6]);\
  IDL_ENSURE_SCALAR(argv[7]);\
  IDL_EXCLUDE_STRING(argv[7]);\
  IDL_ENSURE_SIMPLE(argv[7]);\
  IDL_ENSURE_SCALAR(argv[8]);\
  IDL_EXCLUDE_STRING(argv[8]);\
  IDL_ENSURE_SIMPLE(argv[8]);\
  Z = IDL_LongScalar(argv[0]);\
  Z2 = (float) IDL_DoubleScalar(argv[1]);\
  Z3 = (float) IDL_DoubleScalar(argv[2]);\
  Z4 = (float) IDL_DoubleScalar(argv[3]);\
  Z5 = (float) IDL_DoubleScalar(argv[4]);\
  Z6 = (float) IDL_DoubleScalar(argv[5]);\
  Z7 = (float) IDL_DoubleScalar(argv[6]);\
  Z8 = (float) IDL_DoubleScalar(argv[7]);\
  Z9 = (float) IDL_DoubleScalar(argv[8]);\
  \
  out_var = IDL_Gettmp();\
  out_var->type = IDL_TYP_FLOAT;\
  out_var->value.f = name(Z, Z2, Z3, Z4, Z5, Z6, Z7, Z8, Z9);\
  \
  return out_var;\
}
#define XRL_10IFFFFFFFFF(name) IDL_VPTR IDL_CDECL IDL_ ## name(int argc, IDL_VPTR argv[])\
{\
  int Z;\
  float Z2;\
  float Z3;\
  float Z4;\
  float Z5;\
  float Z6;\
  float Z7;\
  float Z8;\
  float Z9;\
  float Z10;\
  IDL_VPTR out_var;\
  \
  IDL_ENSURE_SCALAR(argv[0]);\
  IDL_EXCLUDE_STRING(argv[0]);\
  IDL_ENSURE_SIMPLE(argv[0]);\
  IDL_ENSURE_SCALAR(argv[1]);\
  IDL_EXCLUDE_STRING(argv[1]);\
  IDL_ENSURE_SIMPLE(argv[1]);\
  IDL_ENSURE_SCALAR(argv[2]);\
  IDL_EXCLUDE_STRING(argv[2]);\
  IDL_ENSURE_SIMPLE(argv[2]);\
  IDL_ENSURE_SCALAR(argv[3]);\
  IDL_EXCLUDE_STRING(argv[3]);\
  IDL_ENSURE_SIMPLE(argv[3]);\
  IDL_ENSURE_SCALAR(argv[4]);\
  IDL_EXCLUDE_STRING(argv[4]);\
  IDL_ENSURE_SIMPLE(argv[4]);\
  IDL_ENSURE_SCALAR(argv[5]);\
  IDL_EXCLUDE_STRING(argv[5]);\
  IDL_ENSURE_SIMPLE(argv[5]);\
  IDL_ENSURE_SCALAR(argv[6]);\
  IDL_EXCLUDE_STRING(argv[6]);\
  IDL_ENSURE_SIMPLE(argv[6]);\
  IDL_ENSURE_SCALAR(argv[7]);\
  IDL_EXCLUDE_STRING(argv[7]);\
  IDL_ENSURE_SIMPLE(argv[7]);\
  IDL_ENSURE_SCALAR(argv[8]);\
  IDL_EXCLUDE_STRING(argv[8]);\
  IDL_ENSURE_SIMPLE(argv[8]);\
  IDL_ENSURE_SCALAR(argv[9]);\
  IDL_EXCLUDE_STRING(argv[9]);\
  IDL_ENSURE_SIMPLE(argv[9]);\
  Z = IDL_LongScalar(argv[0]);\
  Z2 = (float) IDL_DoubleScalar(argv[1]);\
  Z3 = (float) IDL_DoubleScalar(argv[2]);\
  Z4 = (float) IDL_DoubleScalar(argv[3]);\
  Z5 = (float) IDL_DoubleScalar(argv[4]);\
  Z6 = (float) IDL_DoubleScalar(argv[5]);\
  Z7 = (float) IDL_DoubleScalar(argv[6]);\
  Z8 = (float) IDL_DoubleScalar(argv[7]);\
  Z9 = (float) IDL_DoubleScalar(argv[8]);\
  Z10 = (float) IDL_DoubleScalar(argv[9]);\
  \
  out_var = IDL_Gettmp();\
  out_var->type = IDL_TYP_FLOAT;\
  out_var->value.f = name(Z, Z2, Z3, Z4, Z5, Z6, Z7, Z8, Z9, Z10);\
  \
  return out_var;\
}

/*2 arguments: 1 string, 1 float */
#define XRL_2SF(name) IDL_VPTR IDL_CDECL IDL_ ## name(int argc, IDL_VPTR argv[])\
{\
  char *compound;\
  float E;\
  IDL_VPTR out_var;\
  \
  IDL_ENSURE_SCALAR(argv[0]);\
  IDL_ENSURE_STRING(argv[0]);\
  IDL_ENSURE_SCALAR(argv[1]);\
  IDL_EXCLUDE_STRING(argv[1]);\
  IDL_ENSURE_SIMPLE(argv[1]);\
  compound = IDL_VarGetString(argv[0]);\
  E = (float)IDL_DoubleScalar(argv[1]);\
  \
  out_var = IDL_Gettmp();\
  out_var->type = IDL_TYP_FLOAT;\
  out_var->value.f = name(compound, E);\
  \
  return out_var;\
}

/*3 arguments: 1 string, 2 float */
#define XRL_3SFF(name) IDL_VPTR IDL_CDECL IDL_ ## name(int argc, IDL_VPTR argv[])\
{\
  char *compound;\
  float E;\
  float theta;\
  IDL_VPTR out_var;\
  \
  IDL_ENSURE_SCALAR(argv[0]);\
  IDL_ENSURE_STRING(argv[0]);\
  IDL_ENSURE_SCALAR(argv[1]);\
  IDL_EXCLUDE_STRING(argv[1]);\
  IDL_ENSURE_SIMPLE(argv[1]);\
  IDL_ENSURE_SCALAR(argv[2]);\
  IDL_EXCLUDE_STRING(argv[2]);\
  IDL_ENSURE_SIMPLE(argv[2]);\
  compound = IDL_VarGetString(argv[0]);\
  E = (float)IDL_DoubleScalar(argv[1]);\
  theta = (float)IDL_DoubleScalar(argv[2]);\
  \
  out_var = IDL_Gettmp();\
  out_var->type = IDL_TYP_FLOAT;\
  out_var->value.f = name(compound, E,theta);\
  \
  return out_var;\
}

/*4 arguments: 1 string, 3 float */
#define XRL_4SFFF(name) IDL_VPTR IDL_CDECL IDL_ ## name(int argc, IDL_VPTR argv[])\
{\
  char *compound;\
  float E;\
  float theta;\
  float phi;\
  IDL_VPTR out_var;\
  \
  IDL_ENSURE_SCALAR(argv[0]);\
  IDL_ENSURE_STRING(argv[0]);\
  IDL_ENSURE_SCALAR(argv[1]);\
  IDL_EXCLUDE_STRING(argv[1]);\
  IDL_ENSURE_SIMPLE(argv[1]);\
  IDL_ENSURE_SCALAR(argv[2]);\
  IDL_EXCLUDE_STRING(argv[2]);\
  IDL_ENSURE_SIMPLE(argv[2]);\
  IDL_ENSURE_SCALAR(argv[3]);\
  IDL_EXCLUDE_STRING(argv[3]);\
  IDL_ENSURE_SIMPLE(argv[3]);\
  compound = IDL_VarGetString(argv[0]);\
  E = (float)IDL_DoubleScalar(argv[1]);\
  theta = (float)IDL_DoubleScalar(argv[2]);\
  phi = (float)IDL_DoubleScalar(argv[3]);\
  \
  out_var = IDL_Gettmp();\
  out_var->type = IDL_TYP_FLOAT;\
  out_var->value.f = name(compound, E,theta,phi);\
  \
  return out_var;\
}

/*3 arguments: 1 string, 1 int, 1 float*/
#define XRL_3SIF(name) IDL_VPTR IDL_CDECL IDL_ ## name(int argc, IDL_VPTR argv[])\
{\
  char *compound;\
  int shell;\
  float E;\
  IDL_VPTR out_var;\
  \
  IDL_ENSURE_SCALAR(argv[0]);\
  IDL_ENSURE_STRING(argv[0]);\
  IDL_ENSURE_SCALAR(argv[1]);\
  IDL_EXCLUDE_STRING(argv[1]);\
  IDL_ENSURE_SIMPLE(argv[1]);\
  IDL_ENSURE_SCALAR(argv[2]);\
  IDL_EXCLUDE_STRING(argv[2]);\
  IDL_ENSURE_SIMPLE(argv[2]);\
  compound = IDL_VarGetString(argv[0]);\
  shell = (int)IDL_LongScalar(argv[1]);\
  E = (float)IDL_DoubleScalar(argv[2]);\
  \
  out_var = IDL_Gettmp();\
  out_var->type = IDL_TYP_FLOAT;\
  out_var->value.f = name(compound, shell,E);\
  \
  return out_var;\
}


XRL_1I(AtomicWeight)
XRL_1I(ElementDensity)
XRL_1F(CS_KN)
XRL_1F(DCS_Thoms)
XRL_2IF(CS_Total)
XRL_2IF(CS_Photo)
XRL_2IF(CS_Rayl)
XRL_2IF(CS_Compt)
XRL_2IF(CS_Energy)
XRL_2IF(CSb_Total)
XRL_2IF(CSb_Photo)
XRL_2IF(CSb_Rayl)
XRL_2IF(CSb_Compt)
XRL_2IF(FF_Rayl)
XRL_2IF(SF_Compt)
XRL_2IF(Fi)
XRL_2IF(Fii)
XRL_2IF(CS_Photo_Total)
XRL_2IF(CSb_Photo_Total)
XRL_2IF(CS_Total_Kissel)
XRL_2IF(CSb_Total_Kissel)
XRL_2II(LineEnergy)
XRL_2II(FluorYield)
XRL_2II(CosKronTransProb)
XRL_2II(EdgeEnergy)
XRL_2II(JumpFactor)
XRL_2II(RadRate)
XRL_2FF(DCS_KN)
XRL_2FF(DCSP_Thoms)
XRL_2FF(MomentTransf)
XRL_2FF(ComptonEnergy)
XRL_3IFF(DCS_Rayl)
XRL_3IFF(DCS_Compt)
XRL_3IFF(DCSb_Rayl)
XRL_3IFF(DCSb_Compt)
XRL_3FFF(DCSP_KN)
XRL_3IIF(CS_FluorLine)
XRL_3IIF(CSb_FluorLine)
XRL_3IIF(CS_Photo_Partial)
XRL_3IIF(CSb_Photo_Partial)
XRL_4IFFF(DCSP_Rayl)
XRL_4IFFF(DCSP_Compt)
XRL_4IFFF(DCSPb_Rayl)
XRL_4IFFF(DCSPb_Compt)

XRL_2SF(CS_Total_CP)
XRL_2SF(CS_Photo_CP)
XRL_2SF(CS_Rayl_CP)
XRL_2SF(CS_Compt_CP)
XRL_2SF(CS_Energy_CP)
XRL_2SF(CSb_Total_CP)
XRL_2SF(CSb_Photo_CP)
XRL_2SF(CSb_Rayl_CP)
XRL_2SF(CSb_Compt_CP)
XRL_3SFF(DCS_Rayl_CP)
XRL_3SFF(DCS_Compt_CP)
XRL_3SFF(DCSb_Rayl_CP)
XRL_3SFF(DCSb_Compt_CP)
XRL_4SFFF(DCSP_Rayl_CP)
XRL_4SFFF(DCSP_Compt_CP)
XRL_4SFFF(DCSPb_Rayl_CP)
XRL_4SFFF(DCSPb_Compt_CP)
XRL_2SF(CS_Photo_Total_CP)
XRL_2SF(CSb_Photo_Total_CP)
XRL_2SF(CS_Total_Kissel_CP)
XRL_2SF(CSb_Total_Kissel_CP)
XRL_3SFF(Refractive_Index_Re)
XRL_3SFF(Refractive_Index_Im)
XRL_2IF(ComptonProfile)
XRL_3IIF(ComptonProfile_Partial)
XRL_2II(ElectronConfig)
XRL_2II(AtomicLevelWidth)
XRL_2II(AugerRate)
XRL_2II(AugerYield)
XRL_3IIF(CS_FluorLine_Kissel)
XRL_3IIF(CSb_FluorLine_Kissel)
XRL_3IIF(CS_FluorLine_Kissel_Cascade)
XRL_3IIF(CSb_FluorLine_Kissel_Cascade)
XRL_3IIF(CS_FluorLine_Kissel_no_Cascade)
XRL_3IIF(CSb_FluorLine_Kissel_no_Cascade)
XRL_3IIF(CS_FluorLine_Kissel_Nonradiative_Cascade)
XRL_3IIF(CSb_FluorLine_Kissel_Nonradiative_Cascade)
XRL_3IIF(CS_FluorLine_Kissel_Radiative_Cascade)
XRL_3IIF(CSb_FluorLine_Kissel_Radiative_Cascade)
XRL_2IF(PL1_pure_kissel)
XRL_3IFF(PL1_rad_cascade_kissel)
XRL_3IFF(PL1_auger_cascade_kissel)
XRL_3IFF(PL1_full_cascade_kissel)
XRL_3IFF(PL2_pure_kissel)
XRL_4IFFF(PL2_rad_cascade_kissel)
XRL_4IFFF(PL2_auger_cascade_kissel)
XRL_4IFFF(PL2_full_cascade_kissel)
XRL_4IFFF(PL3_pure_kissel)
XRL_5IFFFF(PL3_rad_cascade_kissel)
XRL_5IFFFF(PL3_auger_cascade_kissel)
XRL_5IFFFF(PL3_full_cascade_kissel)
XRL_2IF(PM1_pure_kissel)
XRL_6IFFFFF(PM1_rad_cascade_kissel)
XRL_6IFFFFF(PM1_auger_cascade_kissel)
XRL_6IFFFFF(PM1_full_cascade_kissel)
XRL_3IFF(PM2_pure_kissel)
XRL_7IFFFFFF(PM2_rad_cascade_kissel)
XRL_7IFFFFFF(PM2_auger_cascade_kissel)
XRL_7IFFFFFF(PM2_full_cascade_kissel)
XRL_4IFFF(PM3_pure_kissel)
XRL_8IFFFFFFF(PM3_rad_cascade_kissel)
XRL_8IFFFFFFF(PM3_auger_cascade_kissel)
XRL_8IFFFFFFF(PM3_full_cascade_kissel)
XRL_5IFFFF(PM4_pure_kissel)
XRL_9IFFFFFFFF(PM4_rad_cascade_kissel)
XRL_9IFFFFFFFF(PM4_auger_cascade_kissel)
XRL_9IFFFFFFFF(PM4_full_cascade_kissel)
XRL_6IFFFFF(PM5_pure_kissel)
XRL_10IFFFFFFFFF(PM5_rad_cascade_kissel)
XRL_10IFFFFFFFFF(PM5_auger_cascade_kissel)
XRL_10IFFFFFFFFF(PM5_full_cascade_kissel)


void release(UCHAR *memPtr) {
	free(memPtr);
}

IDL_VPTR IDL_CDECL IDL_CompoundParser(int argc, IDL_VPTR argv[]) {
	struct compoundData *cd;	
	IDL_VPTR rv;

	IDL_ENSURE_STRING(argv[0]);
	IDL_ENSURE_SCALAR(argv[0]);

	if ((cd = CompoundParser(IDL_VarGetString(argv[0]))) == NULL) {
		IDL_Message(IDL_M_NAMED_GENERIC,IDL_MSG_LONGJMP,"Error: check preceding error messages");
	}
	
	IDL_MEMINT array_dims[] = {1,cd->nElements};
	IDL_MEMINT ilDims[IDL_MAX_ARRAY_DIM];
	void *sdef;
	struct compoundData_IDL {
		IDL_LONG nElements;
		double nAtomsAll;
		IDL_LONG Elements[cd->nElements];
		double massFractions[cd->nElements];
	};
	struct compoundData_IDL *cdi;
	IDL_STRUCT_TAG_DEF s_tags[] = {
		{"NELEMENTS", 0, (void *) IDL_TYP_LONG},
		{"NATOMSALL", 0, (void *) IDL_TYP_DOUBLE},
		{"ELEMENTS", array_dims, (void *) IDL_TYP_LONG},
		{"MASSFRACTIONS", array_dims, (void *) IDL_TYP_DOUBLE},
		{0}
	};
	cdi = (struct compoundData_IDL *) malloc(sizeof(struct compoundData_IDL));
	cdi->nElements = cd->nElements;
	cdi->nAtomsAll = cd->nAtomsAll;
	memcpy(cdi->Elements,cd->Elements,sizeof(int)*cd->nElements);
	memcpy(cdi->massFractions,cd->massFractions,sizeof(double)*cd->nElements);
	FreeCompoundData(cd);
	sdef = IDL_MakeStruct(NULL,s_tags);
	ilDims[0] = 1;
	rv=IDL_ImportArray(1,ilDims, IDL_TYP_STRUCT,(UCHAR *) cdi, release,sdef);

	return rv;
}

IDL_VPTR IDL_CDECL IDL_AtomicNumberToSymbol(int argc, IDL_VPTR argv[]) {
	int Z;
	char *symbol;
	
	IDL_ENSURE_SCALAR(argv[0]);
	IDL_EXCLUDE_STRING(argv[0]);
  	IDL_ENSURE_SIMPLE(argv[0]);
	Z = IDL_LongScalar(argv[0]);

	symbol = AtomicNumberToSymbol(Z);

	if (symbol == NULL) {
		return IDL_StrToSTRING("");
	}
	
	return IDL_StrToSTRING(symbol);

}

IDL_VPTR IDL_CDECL IDL_SymbolToAtomicNumber(int argc, IDL_VPTR argv[]) {
	IDL_VPTR out_var;

	IDL_ENSURE_SCALAR(argv[0]);
	IDL_ENSURE_STRING(argv[0]);
  	IDL_ENSURE_SIMPLE(argv[0]);

	out_var = IDL_GettmpLong((IDL_LONG) SymbolToAtomicNumber(IDL_VarGetString(argv[0])));

	return out_var;
}


IDL_VPTR IDL_CDECL IDL_Crystal_GetCrystal(int argc, IDL_VPTR argv[]) {

	IDL_ENSURE_SCALAR(argv[0]);
	IDL_ENSURE_STRING(argv[0]);
  	IDL_ENSURE_SIMPLE(argv[0]);

	Crystal_Struct *cryst = Crystal_GetCrystal(IDL_VarGetString(argv[0]), NULL);

	if (cryst == NULL) {
		IDL_Message(IDL_M_NAMED_GENERIC,IDL_MSG_LONGJMP,"Error: check preceding error messages");
	}


	// First create the CrystalAtom struct array	
	IDL_MEMINT array_dims_atom[] = {1, cryst->n_atom};
	void *sdef_atom;

	IDL_STRUCT_TAG_DEF s_tags_atom[] = {
		{"ZATOM", 0, (void *) IDL_TYP_LONG},
		{"FRACTION", 0, (void *) IDL_TYP_FLOAT},
		{"X", 0 , (void *) IDL_TYP_FLOAT},
		{"Y", 0 , (void *) IDL_TYP_FLOAT},
		{"Z", 0 , (void *) IDL_TYP_FLOAT},
		{0}
	};

	sdef_atom = IDL_MakeStruct(NULL,s_tags_atom);
	IDL_MEMINT dims_atom[IDL_MAX_ARRAY_DIM];
	dims_atom[0] = cryst->n_atom;

	IDL_STRUCT_TAG_DEF s_tags_struct[] = {
		{"NAME", 0, (void *) IDL_TYP_STRING},
		{"A", 0, (void *) IDL_TYP_FLOAT},
		{"B", 0, (void *) IDL_TYP_FLOAT},
		{"C", 0, (void *) IDL_TYP_FLOAT},
		{"ALPHA", 0 , (void *) IDL_TYP_FLOAT},
		{"BETA", 0 , (void *) IDL_TYP_FLOAT},
		{"GAMMA", 0 , (void *) IDL_TYP_FLOAT},
		{"VOLUME", 0 , (void *) IDL_TYP_FLOAT},
		{"N_ATOM", 0 , (void *) IDL_TYP_LONG},
		{"ATOM", array_dims_atom , sdef_atom},
		{0}
	};

	void *sdef_struct = IDL_MakeStruct(NULL, s_tags_struct);
	struct Crystal_Struct_IDL {
		IDL_STRING name;
		float a;
		float b;
		float c;
		float alpha;
		float beta;
		float gamma;
		float volume;
		IDL_LONG n_atom;
		Crystal_Atom atom[cryst->n_atom];
	};

	struct Crystal_Struct_IDL *csi = (struct Crystal_Struct_IDL *) malloc(sizeof(struct Crystal_Struct_IDL));
	IDL_StrStore(&(csi->name),cryst->name);
	csi->a = cryst->a;
	csi->b = cryst->b;
	csi->c = cryst->c;
	csi->alpha = cryst->alpha;
	csi->beta = cryst->beta;
	csi->gamma = cryst->gamma;
	csi->volume = cryst->volume;
	csi->n_atom = cryst->n_atom;
	memcpy(csi->atom,cryst->atom, cryst->n_atom*sizeof(Crystal_Atom));

	IDL_MEMINT dims_cryst[IDL_MAX_ARRAY_DIM];
	dims_cryst[0] = 1;
	IDL_VPTR rv = IDL_ImportArray(1, dims_cryst, IDL_TYP_STRUCT, (UCHAR *) csi, release, sdef_struct);
	
	return rv;
}

static Crystal_Struct * Get_Crystal_Struct(IDL_VPTR arg) {
	IDL_MEMINT offset = IDL_StructTagInfoByName(arg->value.s.sdef,"N_ATOM",IDL_MSG_LONGJMP, NULL);
	IDL_MEMINT n;
	char *data;
	IDL_VarGetData(arg,&n, (char **) &data, FALSE);
	char *n_atom_data = data+offset;
	int n_atom = *((int *) n_atom_data);

	Crystal_Struct *cs = (Crystal_Struct *) malloc(sizeof(Crystal_Struct));
	
	struct Crystal_Struct_IDL {
		IDL_STRING name;
		float a;
		float b;
		float c;
		float alpha;
		float beta;
		float gamma;
		float volume;
		IDL_LONG n_atom;
		Crystal_Atom atom[n_atom];
	};

	struct Crystal_Struct_IDL *csi = (struct Crystal_Struct_IDL *) data;
	cs->a = csi->a;
	cs->b = csi->b;
	cs->c = csi->c;
	cs->alpha = csi->alpha;
	cs->beta= csi->beta;
	cs->gamma = csi->gamma;
	cs->volume = csi->volume;
	cs->n_atom = csi->n_atom;
	cs->atom = csi->atom;

	return cs;
}

IDL_VPTR IDL_CDECL IDL_Bragg_angle(int argc, IDL_VPTR argv[]) {
	IDL_ENSURE_STRUCTURE(argv[0]);

	float energy = (float) IDL_DoubleScalar(argv[1]);
	int i_miller = (int) IDL_LongScalar(argv[2]);
	int j_miller = (int) IDL_LongScalar(argv[3]);
	int k_miller = (int) IDL_LongScalar(argv[4]);

	Crystal_Struct *cs = Get_Crystal_Struct(argv[0]);
	IDL_VPTR rv = IDL_Gettmp();
  	rv->type = IDL_TYP_FLOAT;
  	rv->value.f = Bragg_angle(cs, energy, i_miller, j_miller, k_miller);

	free(cs);
	return rv;
}

IDL_VPTR IDL_CDECL IDL_Q_scattering_amplitude(int argc, IDL_VPTR argv[]) {
	IDL_ENSURE_STRUCTURE(argv[0]);

	float energy = (float) IDL_DoubleScalar(argv[1]);
	int i_miller = (int) IDL_LongScalar(argv[2]);
	int j_miller = (int) IDL_LongScalar(argv[3]);
	int k_miller = (int) IDL_LongScalar(argv[4]);
	float rel_angle = (float) IDL_DoubleScalar(argv[5]);

	Crystal_Struct *cs = Get_Crystal_Struct(argv[0]);
	IDL_VPTR rv = IDL_Gettmp();
  	rv->type = IDL_TYP_FLOAT;
  	rv->value.f = Q_scattering_amplitude(cs, energy, i_miller, j_miller, k_miller, rel_angle);

	free(cs);
	return rv;
}

void IDL_CDECL IDL_Atomic_Factors(int argc, IDL_VPTR argv[]) {
	IDL_EXCLUDE_EXPR(argv[4]);
	IDL_EXCLUDE_EXPR(argv[5]);
	IDL_EXCLUDE_EXPR(argv[6]);
	
	int Z = (int) IDL_LongScalar(argv[0]);
	float energy = (float) IDL_DoubleScalar(argv[1]);
	float q = (float) IDL_DoubleScalar(argv[2]);
	float debye_factor = (float) IDL_DoubleScalar(argv[3]);

	float f0, f_primep, f_prime2;

	Atomic_Factors(Z, energy, q , debye_factor, &f0, &f_primep, &f_prime2);

	IDL_StoreScalar(argv[4], IDL_TYP_FLOAT, (IDL_ALLTYPES *) &f0);
	IDL_StoreScalar(argv[5], IDL_TYP_FLOAT, (IDL_ALLTYPES *) &f_primep);
	IDL_StoreScalar(argv[6], IDL_TYP_FLOAT, (IDL_ALLTYPES *) &f_prime2);
	return;
}

IDL_VPTR IDL_CDECL IDL_Crystal_F_H_StructureFactor(int argc, IDL_VPTR argv[]) {
	IDL_ENSURE_STRUCTURE(argv[0]);

	float energy = (float) IDL_DoubleScalar(argv[1]);
	int i_miller = (int) IDL_LongScalar(argv[2]);
	int j_miller = (int) IDL_LongScalar(argv[3]);
	int k_miller = (int) IDL_LongScalar(argv[4]);
	float debye_factor = (float) IDL_DoubleScalar(argv[5]);
	float rel_angle = (float) IDL_DoubleScalar(argv[6]);

	Crystal_Struct *cs = Get_Crystal_Struct(argv[0]);
	IDL_VPTR rv = IDL_Gettmp();
  	rv->type = IDL_TYP_DCOMPLEX;
	Complex F = Crystal_F_H_StructureFactor (cs, energy, i_miller, j_miller, k_miller, debye_factor, rel_angle);
  	rv->value.dcmp.r = F.re; 
  	rv->value.dcmp.i = F.im; 

	free(cs);
	return rv;


}

IDL_VPTR IDL_CDECL IDL_Crystal_F_H_StructureFactor_Partial(int argc, IDL_VPTR argv[]) {
	IDL_ENSURE_STRUCTURE(argv[0]);

	float energy = (float) IDL_DoubleScalar(argv[1]);
	int i_miller = (int) IDL_LongScalar(argv[2]);
	int j_miller = (int) IDL_LongScalar(argv[3]);
	int k_miller = (int) IDL_LongScalar(argv[4]);
	float debye_factor = (float) IDL_DoubleScalar(argv[5]);
	float rel_angle = (float) IDL_DoubleScalar(argv[6]);
	int f0_flag = (int) IDL_LongScalar(argv[7]);
	int f_prime_flag = (int) IDL_LongScalar(argv[8]);
	int f_prime2_flag = (int) IDL_LongScalar(argv[9]);

	Crystal_Struct *cs = Get_Crystal_Struct(argv[0]);
	IDL_VPTR rv = IDL_Gettmp();
  	rv->type = IDL_TYP_COMPLEX;
	Complex F = Crystal_F_H_StructureFactor_Partial(cs, energy, i_miller, j_miller, k_miller, debye_factor, rel_angle, f0_flag, f_prime_flag, f_prime2_flag);
  	rv->value.cmp.r = F.re; 
  	rv->value.cmp.i = F.im; 

	free(cs);
	return rv;


}

IDL_VPTR IDL_CDECL IDL_Crystal_UnitCellVolume(int argc, IDL_VPTR argv[]) {
	IDL_ENSURE_STRUCTURE(argv[0]);


	Crystal_Struct *cs = Get_Crystal_Struct(argv[0]);
	IDL_VPTR rv = IDL_Gettmp();
  	rv->type = IDL_TYP_FLOAT;
  	rv->value.f = Crystal_UnitCellVolume(cs);

	free(cs);
	return rv;
}

IDL_VPTR IDL_CDECL IDL_Crystal_dSpacing(int argc, IDL_VPTR argv[]) {
	IDL_ENSURE_STRUCTURE(argv[0]);

	int i_miller = (int) IDL_LongScalar(argv[1]);
	int j_miller = (int) IDL_LongScalar(argv[2]);
	int k_miller = (int) IDL_LongScalar(argv[3]);

	Crystal_Struct *cs = Get_Crystal_Struct(argv[0]);
	IDL_VPTR rv = IDL_Gettmp();
  	rv->type = IDL_TYP_FLOAT;
  	rv->value.f = Crystal_dSpacing(cs, i_miller, j_miller, k_miller);

	free(cs);
	return rv;
}

static IDL_VPTR IDL_GetCompoundDataNIST(struct compoundDataNIST *cdn) {
	IDL_VPTR rv;
	IDL_MEMINT array_dims[] = {1, cdn->nElements};
	void *sdef;
	struct compoundDataNIST_IDL {
		IDL_STRING name;
		IDL_LONG nElements;
		IDL_LONG Elements[cdn->nElements];
		double massFractions[cdn->nElements];
		double density;
	};

	struct compoundDataNIST_IDL *cdni;
	IDL_STRUCT_TAG_DEF s_tags[] = {
		{"NAME", 0, (void *) IDL_TYP_STRING},
		{"NELEMENTS", 0, (void *) IDL_TYP_LONG},
		{"ELEMENTS", array_dims, (void *) IDL_TYP_LONG},
		{"MASSFRACTIONS", array_dims, (void *) IDL_TYP_DOUBLE},
		{"DENSITY", 0, (void *) IDL_TYP_DOUBLE},
		{0}
	};

	void *sdef_struct = IDL_MakeStruct(NULL, s_tags);

	cdni = (struct compoundDataNIST_IDL *) malloc(sizeof(struct compoundDataNIST_IDL));
	cdni->nElements = cdn->nElements;
	cdni->density = cdn->density;
	memcpy(cdni->Elements, cdn->Elements, sizeof(int)*cdn->nElements);
	memcpy(cdni->massFractions, cdn->massFractions, sizeof(double)*cdn->nElements);
	IDL_StrStore(&(cdni->name), cdn->name);

	IDL_MEMINT ilDims[IDL_MAX_ARRAY_DIM];
	ilDims[0] = 1;
	//release will probably lead to a small memory leak here due to the name not being freed
	//perhaps to be fixed later on
	rv = IDL_ImportArray(1, ilDims, IDL_TYP_STRUCT, (UCHAR *) cdni, release, sdef_struct);
	return rv;
}

IDL_VPTR IDL_CDECL IDL_GetCompoundDataNISTByName(int argc, IDL_VPTR argv[]) {
  	IDL_ENSURE_STRING(argv[0]);
  	IDL_ENSURE_SCALAR(argv[0]);
  	IDL_ENSURE_SIMPLE(argv[0]);

	IDL_VPTR rv;

	char * compoundString = IDL_VarGetString(argv[0]);
	struct compoundDataNIST *cdn = GetCompoundDataNISTByName(compoundString);
	if (cdn == NULL) {
		IDL_Message(IDL_M_NAMED_GENERIC,IDL_MSG_LONGJMP,"Error: check preceding error messages");
	}

	rv = IDL_GetCompoundDataNIST(cdn); 

	FreeCompoundDataNIST(cdn);

	return rv;
}

IDL_VPTR IDL_CDECL IDL_GetCompoundDataNISTByIndex(int argc, IDL_VPTR argv[]) {
  	IDL_EXCLUDE_STRING(argv[0]);
  	IDL_ENSURE_SCALAR(argv[0]);
  	IDL_ENSURE_SIMPLE(argv[0]);

	IDL_VPTR rv;

	int index = (int) IDL_LongScalar(argv[0]);
	

	struct compoundDataNIST *cdn = GetCompoundDataNISTByIndex(index);
	if (cdn == NULL) {
		IDL_Message(IDL_M_NAMED_GENERIC,IDL_MSG_LONGJMP,"Error: check preceding error messages");
	}

	rv = IDL_GetCompoundDataNIST(cdn); 

	FreeCompoundDataNIST(cdn);

	return rv;
}

IDL_VPTR IDL_CDECL IDL_GetCompoundDataNISTList(int argc, IDL_VPTR argv[]) {
	IDL_VPTR rv;

	int nCompounds;
	char **list = GetCompoundDataNISTList(&nCompounds);
	IDL_STRING *list_IDL;
	IDL_MEMINT dims[IDL_MAX_ARRAY_DIM];
	dims[0] = nCompounds;

	list_IDL = (IDL_STRING*) IDL_MakeTempArray((int) IDL_TYP_STRING, 1, dims, IDL_ARR_INI_NOP, &rv);

	int i;
	int slen;

	for (i = 0 ; i < nCompounds ; i++) {
		slen = strlen(list[i]);
		IDL_StrEnsureLength(&(list_IDL[i]), slen);
		IDL_StrStore(&(list_IDL[i]), list[i]);
		list_IDL[i].slen = slen;
		xrlFree(list[i]);
	}
	xrlFree(list);

	return rv;
}

int IDL_Load (void) 
{
	return IDL_SysRtnAdd(xrl_functions, TRUE, IDL_CARRAY_ELTS(xrl_functions)) &&
                IDL_SysRtnAdd(xrl_procedures, FALSE, IDL_CARRAY_ELTS(xrl_procedures));
}
