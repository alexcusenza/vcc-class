/*
 * modstruct.cpp
 *
 *  Created on: Mar 6, 2014
 *      Author: acusenza
 */




/*******************************************************************************
MODULE NAME:  modstruct.h

GENERAL DESCRIPTION:

 ********************************************************************************/

/*********************************************************************************
COMMENTS:

2013/03: A.Cusenza
- Modbus structure initial release
- SickCPU0, SickCPU1 and PLC Type Definitions

2013/04: A.Cusenza
- added modbus structure to Hawk Project
- separated SickCPU structures to InputType and OutputType

2013/05: A.Cusenza
- changed structures from Anonymous to Declared Types.  CPU0 and CPU1 both had
identical anonymous structures and was getting confused using in the editor.
Changing to declared type proved more robust in accessing members.

 ********************************************************************************/

#ifndef _ModStructs_H
#define _ModStructs_H


// STRUCTURE DEFINITIONS
// ---------------------
struct ModuleCPU0_Input_Type
{
	bool Aux1monitor : 1;			//lsb
	bool Aux2monitor : 1;
	bool NavMgrEstop : 1;
	bool VehMgrEstop : 1;
	bool spare_b4 : 1;
	bool spare_b5 : 1;
	bool spare_b6 : 1;
	bool FromCPU1Estop : 1;			//msb
};

struct ModuleCPU0_Output_Type
{
	bool CRM1 : 1;
	bool CRM2 : 1;
	bool Enable : 1;
	bool Precharge : 1;
	bool spare_b4 : 1;
	bool spare_b5 : 1;
	bool spare_b6 : 1;
	bool spare_b7 : 1;
};

struct ModuleCPU1_Input_Type
{
	bool EStop1 : 1;
	bool EStop2 : 1;
	bool EStop3 : 1;
	bool EStop4 : 1;
	bool EStop5 : 1;
	bool EStop6 : 1;
	bool EStopCom : 1;
	bool spare_b7 : 1;
};

struct ModuleCPU1_Output_Type
{
	bool ToCPU0Estop : 1;
	bool spare_b1 : 1;
	bool spare_b2 : 1;
	bool spare_b3 : 1;
	bool spare_b4 : 1;
	bool spare_b5 : 1;
	bool spare_b6 : 1;
	bool spare_b7 : 1;
};


struct Status_Input_B1_Type
{
	bool Status_Input_data : 1;
	bool unused_b1 : 1;
	bool unused_b2 : 1;
	bool unused_b3 : 1;
	bool unused_b4 : 1;
	bool unused_b5 : 1;
	bool unused_b6 : 1;
	bool unused_b7 : 1;
};

struct Status_Input_B2_Type
{
	bool unused_b0 : 1;
	bool unused_b1 : 1;
	bool unused_b2 : 1;
	bool unused_b3 : 1;
	bool VehMgrComms_Status_Input_data : 1;
	bool unused_b5 : 1;
	bool unused_b6 : 1;
	bool unused_b7 : 1;
};

struct Status_Output_B1_Type
{
	bool Status_Output_data : 1;
	bool unused_b1 : 1;
	bool unused_b2 : 1;
	bool unused_b3 : 1;
	bool unused_b4 : 1;
	bool unused_b5 : 1;
	bool unused_b6 : 1;
	bool unused_b7 : 1;
};

struct Status_Output_B2_Type
{
	bool unused_b0 : 1;
	bool unused_b1 : 1;
	bool unused_b2 : 1;
	bool unused_b3 : 1;
	bool VehMgrComms_Status_Output_data : 1;
	bool unused_b5 : 1;
	bool unused_b6 : 1;
	bool unused_b7 : 1;
};

struct Location_Status_B1_Type
{
	bool CPU_Location_Status : 1;
	bool SafetyIO_Location_Status : 1;
	bool unused_b2 : 1;
	bool unused_b3 : 1;
	bool unused_b4 : 1;
	bool unused_b5 : 1;
	bool unused_b6 : 1;
	bool unused_b7 : 1;
};

struct Location_Status_B2_Type
{
	bool unused_b0 : 1;
	bool unused_b1 : 1;
	bool unused_b2 : 1;
	bool unused_b3 : 1;
	bool unused_b4 : 1;
	bool VehMgrComms_Location_status : 1;
	bool unused_b6 : 1;
	bool unused_b7 : 1;
};

struct EFI_Location_Status_Type
{
	bool CPU_S300Mini_Location_status_b0 : 1;
	bool CPU_S300Mini_Location_status_b1 : 1;
	bool unused_b2 : 1;
	bool CPU_S300Mini_Location_status_b3 : 1;
	bool CPU_S300Mini_Location_status_b4 : 1;
	bool unused_b5 : 1;
	bool unused_b6 : 1;
	bool unused_b7 : 1;
};

struct EFI_Dev_Control_B0_Type
{
	bool unused_b0 : 1;
	bool unused_b1 : 1;
	bool unused_b2 : 1;
	bool unused_b3 : 1;
	bool CPU_InputE1 : 1;
	bool CPU_InputE2 : 1;
	bool CPU_StandByHost : 1;
	bool CPU_StandByGuest : 1;
};

struct EFI_Dev_Control_B1_Type
{
	bool unused_b0 : 1;
	bool CPU_IOError : 1;
	bool unused_b2 : 1;
	bool unused_b3 : 1;
	bool CPU_InputA1 : 1;
	bool CPU_InputA2 : 1;
	bool CPU_InputB1 : 1;
	bool CPU_InputB2 : 1;
};

struct EFI_Dev_Control_B2_Type
{
	bool CPU_InputC1 : 1;
	bool CPU_InputC2 : 1;
	bool CPU_InputD1 : 1;
	bool CPU_InputD2 : 1;
	bool unused_b4 : 1;
	bool unused_b5 : 1;
	bool unused_b6 : 1;
	bool unused_b7 : 1;
};

struct EFI_Dev_Scanner_B0_Type
{
	bool unused_b0 : 1;
	bool unused_b1 : 1;
	bool unused_b2 : 1;
	bool unused_b3 : 1;
	bool unused_b4 : 1;
	bool CPU_ContaminationLED : 1;
	bool CPU_WarningFieldLED : 1;
	bool unused_b7 : 1;
};

struct EFI_Dev_Scanner_B1_Type
{
	bool unused_b0 : 1;
	bool CPU_IOError : 1;
	bool unused_b2 : 1;
	bool unused_b3 : 1;
	bool unused_b4 : 1;
	bool unused_b5 : 1;
	bool unused_b6 : 1;
	bool unused_b7 : 1;
};

struct EFI_Dev_Scanner_B3_Type
{
	bool unused_b0 : 1;
	bool unused_b1 : 1;
	bool unused_b2 : 1;
	bool unused_b3 : 1;
	bool CPU_ProtectiveField : 1;
	bool CPU_WarningField1 : 1;
	bool unused_b6 : 1;
	bool CPU_WarningField2 : 1;
};

struct Logic_Result_0_Type
{
	bool BumperBypass_Ack : 1;
	bool BumperBypass_Active : 1;
	bool Safety_Engaged : 1;
	bool CRM_AuxMonitors : 1;
	bool unused_b4 : 1;
	bool unused_b5 : 1;
	bool unused_b6 : 1;
	bool unused_b7 : 1;

};

struct VehMgrToCPU_B0_Type
{
	bool EFI1_A1 : 1;
	bool EFI1_B1 : 1;
	bool EFI1_C1 : 1;
	bool EFI1_D1 : 1;
	bool EFI1_E1 : 1;
	bool spare_b5 : 1;
	bool spare_b6 : 1;
	bool spare_b7 : 1;
};

struct VehMgrToCPU_B1_Type
{
	bool EFI1_A2 : 1;
	bool EFI1_B2 : 1;
	bool EFI1_C2 : 1;
	bool EFI1_D2 : 1;
	bool EFI1_E2 : 1;
	bool spare_b5 : 1;
	bool spare_b6 : 1;
	bool spare_b7 : 1;
};

struct VehMgrToCPU_B2_Type
{
	bool EFI2_A1 : 1;
	bool EFI2_B1 : 1;
	bool EFI2_C1 : 1;
	bool EFI2_D1 : 1;
	bool EFI2_E1 : 1;
	bool spare_b5 : 1;
	bool spare_b6 : 1;
	bool spare_b7 : 1;
};

struct VehMgrToCPU_B3_Type
{
	bool EFI2_A2 : 1;
	bool EFI2_B2 : 1;
	bool EFI2_C2 : 1;
	bool EFI2_D2 : 1;
	bool EFI2_E2 : 1;
	bool spare_b5 : 1;
	bool spare_b6 : 1;
	bool spare_b7 : 1;

};


struct VehMgrToCPU_B4_Type
{
	bool BumperBypass_Req : 1 ;
	bool spare_b1 : 1 ;
	bool spare_b2 : 1 ;
	bool spare_b3 : 1 ;
	bool spare_b4 : 1 ;
	bool spare_b5 : 1 ;
	bool spare_b6 : 1 ;
	bool spare_b7 : 1 ;
};



// **********************************
// SICK CPU0 TYPE INPUT
// **********************************

struct SickCPU0_InputType
{
	// *** MODULE I/O ***
	// SickCPU0_InputType 0
	union
	{
		ModuleCPU0_Input_Type sCPU0_Module_Input;
		int8u uCPU0_Module_Input;
	};

	// SickCPU0_InputType 1
	union
	{
		ModuleCPU0_Output_Type sCPU0_Module_Output;
		int8u uCPU0_Module_Output;
	};

	// *** STATUS ***
	// SickCPU0_InputType 2
	Status_Input_B1_Type sCPU0_Status_Input_B1;

	// SickCPU0_InputType 3
	Status_Input_B2_Type sCPU0_Status_Input_B2;

	// SickCPU0_InputType 4
	Status_Output_B1_Type sCPU0_Status_Output_B1;

	// SickCPU0_InputType 5
	Status_Output_B2_Type sCPU0_Status_Output_B2;

	// SickCPU0_InputType 6
	Location_Status_B1_Type sCPU0_Location_Status_B1;

	// SickCPU0_InputType 7
	Location_Status_B2_Type sCPU0_Location_Status_B2;

	// SickCPU0_InputType 8
	EFI_Location_Status_Type sCPU0_EFI_Location_Status;

	// *** EFI1 DEVICE 1/2 ***
	// SickCPU0_InputType 9
	EFI_Dev_Control_B0_Type sCPU0_EFI1_Dev0_Control_B0;

	// SickCPU0_InputType 10
	EFI_Dev_Control_B1_Type sCPU0_EFI1_Dev0_Control_B1;

	// SickCPU0_InputType 11
	EFI_Dev_Control_B2_Type sCPU0_EFI1_Dev0_Control_B2;

	// *** EFI1 DEVICE 1 ***
	// SickCPU0_InputType 12
	EFI_Dev_Scanner_B0_Type sCPU0_EFI1_Dev1_Scanner_B0;

	// SickCPU0_InputType 13
	EFI_Dev_Scanner_B1_Type sCPU0_EFI1_Dev1_Scanner_B1;

	// SickCPU0_InputType 14
	EFI_Dev_Scanner_B3_Type sCPU0_EFI1_Dev1_Scanner_B3;

	// *** EFI1 DEVICE 2 ***
	// SickCPU0_InputType 15
	EFI_Dev_Scanner_B0_Type sCPU0_EFI1_Dev2_Scanner_B0;

	// SickCPU0_InputType 16
	EFI_Dev_Scanner_B1_Type sCPU0_EFI1_Dev2_Scanner_B1;

	// SickCPU0_InputType 17
	EFI_Dev_Scanner_B3_Type sCPU0_EFI1_Dev2_Scanner_B3;

	// *** EFI2 DEVICE 1/2 ***
	// SickCPU0_InputType 18
	EFI_Dev_Control_B0_Type sCPU0_EFI2_Dev0_Control_B0;

	// SickCPU0_InputType 19
	EFI_Dev_Control_B1_Type sCPU0_EFI2_Dev0_Control_B1;

	// SickCPU0_InputType 20
	EFI_Dev_Control_B2_Type sCPU0_EFI2_Dev0_Control_B2;

	// *** EFI2 DEVICE 1 ***
	// SickCPU0_InputType 21
	EFI_Dev_Scanner_B0_Type sCPU0_EFI2_Dev1_Scanner_B0;

	// SickCPU0_InputType 22
	EFI_Dev_Scanner_B1_Type sCPU0_EFI2_Dev1_Scanner_B1;

	// SickCPU0_InputType 23
	EFI_Dev_Scanner_B3_Type sCPU0_EFI2_Dev1_Scanner_B3;

	// *** EFI2 DEVICE 2 ***
	// SickCPU0_InputType 24
	EFI_Dev_Scanner_B0_Type sCPU0_EFI2_Dev2_Scanner_B0;

	// SickCPU0_InputType 25
	EFI_Dev_Scanner_B1_Type sCPU0_EFI2_Dev2_Scanner_B1;

	// SickCPU0_InputType 26
	EFI_Dev_Scanner_B3_Type sCPU0_EFI2_Dev2_Scanner_B3;

	Logic_Result_0_Type sCPU0_Logic_Result_0;

	int8u zSpare_B28;
	int8u zSpare_B29;
	int8u zSpare_B30;
	int8u zSpare_B31;
	int8u zSpare_B32;
	int8u zSpare_B33;
	int8u zSpare_B34;
	int8u zSpare_B35;
	int8u zSpare_B36;
	int8u zSpare_B37;
	int8u zSpare_B38;
	int8u zSpare_B39;
	int8u zSpare_B40;
	int8u zSpare_B41;
	int8u zSpare_B42;
	int8u zSpare_B43;
	int8u zSpare_B44;
	int8u zSpare_B45;
	int8u zSpare_B46;
	int8u zSpare_B47;
	int8u zSpare_B48;
	int8u zSpare_B49;

};

// **********************************
// SICK CPU0 TYPE OUTPUT
// **********************************

struct SickCPU0_OutputType
{

	union
	{
		VehMgrToCPU_B0_Type sVehMgrToCPU0_B0;
		int8u uVehMgrToCPU0_B0;
	};

	union
	{
		VehMgrToCPU_B1_Type sVehMgrToCPU0_B1;
		int8u uVehMgrToCPU0_B1;
	};

	union
	{
		VehMgrToCPU_B2_Type sVehMgrToCPU0_B2;
		int8u uVehMgrToCPU0_B2;
	};

	union
	{
		VehMgrToCPU_B3_Type sVehMgrToCPU0_B3;
		int8u uVehMgrToCPU0_B3;
	};

	union
	{
		VehMgrToCPU_B4_Type sVehMgrToCPU0_B4;
		int8u uVehMgrToCPU0_B4;
	};

	int8u zSpare_B5;
	int8u zSpare_B6;
	int8u zSpare_B7;
	int8u zSpare_B8;
	int8u zSpare_B9;


};

// **********************************
// SICK CPU1 TYPE INPUT
// **********************************

struct SickCPU1_InputType
{
	// *** MODULE I/O ***
	// SickCPU1_InputType 0
	union
	{
		ModuleCPU1_Input_Type sCPU1_Module_Input;
		int8u uCPU1_Module_Input;
	};

	// SickCPU1_InputType 1
	union
	{
		ModuleCPU1_Output_Type sCPU1_Module_Output;
		int8u uCPU1_Module_Output;
	};


	// *** STATUS ***
	// SickCPU1_InputType 2
	Status_Input_B1_Type sCPU1_Status_Input_B1;

	// SickCPU1_InputType 3
	Status_Input_B2_Type sCPU1_Status_Input_B2;

	// SickCPU1_InputType 4
	Status_Output_B1_Type sCPU1_Status_Output_B1;

	// SickCPU1_InputType 5
	Status_Output_B2_Type sCPU1_Status_Output_B2;

	// SickCPU1_InputType 6
	Location_Status_B1_Type sCPU1_Location_Status_B1;

	// SickCPU1_InputType 7
	Location_Status_B2_Type sCPU1_Location_Status_B2;

	// SickCPU1_InputType 8
	EFI_Location_Status_Type sCPU1_EFI_Location_Status;

	// *** EFI1 DEVICE 1/2 ***
	// SickCPU1_InputType 9
	EFI_Dev_Control_B0_Type sCPU1_EFI1_Dev0_Control_B0;

	// SickCPU1_InputType 10
	EFI_Dev_Control_B1_Type sCPU1_EFI1_Dev0_Control_B1;

	// SickCPU1_InputType 11
	EFI_Dev_Control_B2_Type sCPU1_EFI1_Dev0_Control_B2;

	// *** EFI1 DEVICE 1 ***
	// SickCPU1_InputType 12
	EFI_Dev_Scanner_B0_Type sCPU1_EFI1_Dev1_Scanner_B0;

	// SickCPU1_InputType 13
	EFI_Dev_Scanner_B1_Type sCPU1_EFI1_Dev1_Scanner_B1;

	// SickCPU1_InputType 14
	EFI_Dev_Scanner_B3_Type sCPU1_EFI1_Dev1_Scanner_B3;

	// *** EFI1 DEVICE 2 ***
	// SickCPU1_InputType 15
	EFI_Dev_Scanner_B0_Type sCPU1_EFI1_Dev2_Scanner_B0;

	// SickCPU1_InputType 16
	EFI_Dev_Scanner_B1_Type sCPU1_EFI1_Dev2_Scanner_B1;

	// SickCPU1_InputType 17
	EFI_Dev_Scanner_B3_Type sCPU1_EFI1_Dev2_Scanner_B3;

	// *** EFI2 DEVICE 1/2 ***
	// SickCPU1_InputType 18
	EFI_Dev_Control_B0_Type sCPU1_EFI2_Dev0_Control_B0;

	// SickCPU1_InputType 19
	EFI_Dev_Control_B1_Type sCPU1_EFI2_Dev0_Control_B1;

	// SickCPU1_InputType 20
	EFI_Dev_Control_B2_Type sCPU1_EFI2_Dev0_Control_B2;

	// *** EFI2 DEVICE 1 ***
	// SickCPU1_InputType 21
	EFI_Dev_Scanner_B0_Type sCPU1_EFI2_Dev1_Scanner_B0;

	// SickCPU1_InputType 22
	EFI_Dev_Scanner_B1_Type sCPU1_EFI2_Dev1_Scanner_B1;

	// SickCPU1_InputType 23
	EFI_Dev_Scanner_B3_Type sCPU1_EFI2_Dev1_Scanner_B3;

	// *** EFI2 DEVICE 2 ***
	// SickCPU1_InputType 24
	EFI_Dev_Scanner_B0_Type sCPU1_EFI2_Dev2_Scanner_B0;

	// SickCPU1_InputType 25
	EFI_Dev_Scanner_B1_Type sCPU1_EFI2_Dev2_Scanner_B1;

	// SickCPU1_InputType 26
	EFI_Dev_Scanner_B3_Type sCPU1_EFI2_Dev2_Scanner_B3;

	int8u zSpare_B27;
	int8u zSpare_B28;
	int8u zSpare_B29;
	int8u zSpare_B30;
	int8u zSpare_B31;
	int8u zSpare_B32;
	int8u zSpare_B33;
	int8u zSpare_B34;
	int8u zSpare_B35;
	int8u zSpare_B36;
	int8u zSpare_B37;
	int8u zSpare_B38;
	int8u zSpare_B39;
	int8u zSpare_B40;
	int8u zSpare_B41;
	int8u zSpare_B42;
	int8u zSpare_B43;
	int8u zSpare_B44;
	int8u zSpare_B45;
	int8u zSpare_B46;
	int8u zSpare_B47;
	int8u zSpare_B48;
	int8u zSpare_B49;

};

// **********************************
// SICK CPU1 TYPE OUTPUT
// **********************************

struct SickCPU1_OutputType
{

	union
	{
		VehMgrToCPU_B0_Type sVehMgrToCPU1_B0;
		int8u uVehMgrToCPU1_B0;
	};

	union
	{
		VehMgrToCPU_B1_Type sVehMgrToCPU1_B1;
		int8u uVehMgrToCPU1_B1;
	};

	union
	{
		VehMgrToCPU_B2_Type sVehMgrToCPU1_B2;
		int8u uVehMgrToCPU1_B2;
	};

	union
	{
		VehMgrToCPU_B3_Type sVehMgrToCPU1_B3;
		int8u uVehMgrToCPU1_B3;
	};

	int8u zSpare_B4;
	int8u zSpare_B5;
	int8u zSpare_B6;
	int8u zSpare_B7;
	int8u zSpare_B8;
	int8u zSpare_B9;

};


// *******************************************************************
// PLC Input Map
// *******************************************************************
struct PLC_InputType
{
	// slot 1: KL3132 2 Channel Analog Input Card 16bit
	//int16u CurrentSensor1_Status;
	//int16s CurrentSensor1_AnalogData;
	//int16u CurrentSensor2_Status;
	//int16s CurrentSensor2_AnalogData;
	// slot 7: KL3162 2 Channel Analog Input Card 16bit
	//int16u VoltageSensor3_Status;
	//int16u VoltageSensor3_AnalogData;
	//int16u AnalogSensor4_Status;
	//int16u AnalogSensor4_AnalogData;

	//union
	//{
	//	struct
	//	{
	// slot 2: KL1408 8 channel Digital Sourcing Input Card
	bool ChargeShoe_Raised_Left : 1;
	bool spare_s2_b1 : 1;
	bool ChargeShoe_Raised_Right : 1;
	bool spare_s2_b3 : 1;
	bool BrakeReleased_FrontLeft : 1;
	bool BrakeReleased_FrontRight : 1;
	bool BrakeReleased_RearLeft : 1;
	bool BrakeReleased_RearRight : 1;

	// slot3: KL1408 8 channel Digital Sourcing Input Card
	bool Left_Charge_Contactor_Open : 1;
	bool Right_Charge_Contactor_Open : 1;
	bool Left_Charge_Shoe_Inposition : 1;
	bool Right_Charge_Shoe_Inposition : 1;
	bool Left_Charge_Contactor_Open_Negitive : 1;
	bool spare_s3_b5 : 1;
	bool Left_Side_Step_InPosition : 1;
	bool Right_Side_Step_InPosition : 1;
	//	}Bit_Field;
	//	int16u PLC_Input_Word1;
	//};
};




// *******************************************************************
// PLC Output Map
// *******************************************************************
struct PLC_OutputType
{
	union
	{
		struct
		{
			// slot4: KL2022 2 channel Digital Sourcing Output Card
			bool Left_Charge_Contactor : 1;
			bool Right_Charge_Contactor : 1;
			// slot5: KL2408 8 Channel Digital Sourcing Output Card
			bool Beacon_White_LeftSide : 1;
			bool Beacon_Amber_LeftSide : 1;
			bool Beacon_Red_LeftSide : 1;
			bool Horn_LeftSide : 1;
			bool Beacon_White_RightSide : 1;
			bool Beacon_Amber_RightSide : 1;

			bool Beacon_Red_RightSide : 1;
			bool Horn_RightSide : 1;
			// slot6: KL2408 8 Channel Digital Sourcing Output Card
			bool ChargeShoe_Actuator_Left_Raise : 1;
			bool ChargeShoe_Actuator_Left_Lower : 1;
			bool ChargeShoe_Actuator_Right_Raise : 1;
			bool ChargeShoe_Actuator_Right_Lower : 1;
			bool VehMgr_Estop : 1;
			bool spare_s2_b7 : 1;
		}Bit_Field1;

		int16u PLC_Output_Word1;
	};

	union
	{
		struct
		{
			bool spare_s3_b0 : 1;
			bool spare_s3_b1 : 1;
			bool spare_s3_b2 : 1;
			bool spare_s3_b3 : 1;
			bool spare_s3_b4 : 1;
			bool spare_s3_b5 : 1;
			bool spare_s3_b6 : 1;
			bool spare_s3_b7 : 1;

			bool spare_s4_b0 : 1;
			bool spare_s4_b1 : 1;
			bool spare_s4_b2 : 1;
			bool spare_s4_b3 : 1;
			bool spare_s4_b4 : 1;
			bool spare_s4_b5 : 1;
			bool spare_s4_b6 : 1;
			bool spare_s4_b7 : 1;
		}Bit_Field2;

		int16u PLC_Output_Word2;
	};
};


// *******************************************************************
// PLC Maintenance Test Map
// *******************************************************************
struct PLC_MaintenanceTestType
{
	union
	{
		struct
		{                                       // Proface address 2176 (word)
			bool DoActiveOutputTest : 1;			// Flag to perform active output test
			bool DoMonitoredOutputTest : 1;		// Flag to perform monitored output test
			bool DoBumperTest : 1;                // Flag to perform Bumper Test
			bool spare_s1_b3 : 1;
			bool spare_s1_b4 : 1;
			bool spare_s1_b5 : 1;
			bool spare_s1_b6 : 1;
			bool spare_s1_b7 : 1;

			bool spare_s2_b0 : 1;
			bool spare_s2_b1 : 1;
			bool spare_s2_b2 : 1;
			bool spare_s2_b3 : 1;
			bool spare_s2_b4 : 1;
			bool spare_s2_b5 : 1;
			bool spare_s2_b6 : 1;
			bool spare_s2_b7 : 1;
		} sMaintTesting1;

		int16u MaintTesting1;
	};

	union
	{
		struct
		{                                       // Proface address 2176 (word)
			bool Safety_Up : 1;                   // Pass/Fail power on, Bumpers on, Estop outputs on, CRC off
			bool EStopPassed : 1;                 // Pass/Fail of Estop circuit was active now off
			bool LeftChargeContactorPassed : 1;   // Pass/Fail of left charge contactor test
			bool RightChargeContactorPassed : 1;  // Pass/Fail of left charge contactor test
			bool PreChargePassed : 1;             // Pass/Fail of Output PreCharge Test
			bool MotorEnablePassed : 1;           // Pass/Fail of Output motor enable Test
			bool AuxContactsPassed : 1;           // Pass/Fail of AUX contacts from CRM 1 & 2 Test
			bool spare_s3_b7 : 1;                 // spare

			bool LeftActuatorPassed : 1;          // Pass/Fail of left charge actuator test
			bool RightActuatorPassed : 1;         // Pass/Fail of right charge actuator test
			bool Analog1Passed : 1;               // Pass/Fail of analog 1 range test
			bool Analog2Passed : 1;               // Pass/Fail of analog 2 range test
			bool Analog3Passed : 1;               // Pass/Fail of analog 3 range test
			bool spare_s4_b5 : 1;
			bool spare_s4_b6 : 1;
			bool BumperTestPassed : 1;            // Pass/Fail of bumper test
		} sMaintTesting2;

		int16u MaintTesting2;
	};
};


// *******************************************************************
// HMI Input Map
// *******************************************************************
struct HMI_MapInputType
{
	bool IN_Destination_Req : 1;
	bool IN_Operation_Req : 1;
	bool IN_Route_Req : 1;
	bool IN_IPAddress_Req : 1;
	bool IN_IPMask_Req : 1;
	bool IN_IPGateway_Req : 1;
	bool IN_ClearHourMeter_Req : 1;
	bool IN_ClearTravelMeter_Req : 1;

	bool IN_GyroCorrection_Req : 1;
	bool IN_Steer0_Offset_Req : 1;
	bool IN_Steer1_Offset_Req : 1;
	bool IN_Steer2_Offset_Req : 1;
	bool IN_Steer3_Offset_Req : 1;
	bool IN_TrackWheel_Offset_Req : 1;
	bool IN_TagWrite_Req : 1;
	bool IN_MagnetValue_Req : 1;

	bool IN_SendMagData_Req : 1;
	bool IN_Mag_Calibration_Req : 1;
	bool spare_B3b2 : 1;
	bool spare_B3b3 : 1;
	bool spare_B3b4 : 1;
	bool spare_B3b5 : 1;
	bool spare_B3b6 : 1;
	bool spare_B3b7 : 1;

	bool IN_ActiveTest_Req : 1;
	bool IN_MonitorTest_Req : 1;
	bool IN_BumperTest_Req : 1;
	bool spare_B4b3 : 1;
	bool spare_B4b4 : 1;
	bool spare_B4b5 : 1;
	bool spare_B4b6 : 1;
	bool spare_B4b7 : 1;

	bool IN_Insert_Req : 1;
	bool IN_Speed_Req : 1;
	bool IN_ObjectInhibit_Req : 1;
	bool spare_B5b3 : 1;
	bool spare_B5b4 : 1;
	bool IN_BumperOverride_Req : 1;
	bool IN_ChargeOn_Req : 1;
	bool IN_ChargeOff_Req : 1;

	bool IN_AutoStart_Req : 1;
	bool spare_B6b1 : 1;
	bool spare_B6b2 : 1;
	bool spare_B6b3 : 1;
	bool IN_Magnetic_Guide_Req : 1;
	bool IN_Laser_Guide_Req : 1;
	bool spare_B6b6 : 1;
	bool spare_B6b7 : 1;

	int8u spare_b7 ;
};


// *******************************************************************
// HMI Output Map
// *******************************************************************
struct HMI_MapOutputType
{
	bool OUT_Destination_Ack : 1;
	bool OUT_Operation_Ack : 1;
	bool OUT_Route_Ack : 1;
	bool OUT_IPAddress_Ack : 1;
	bool OUT_IPMask_Ack : 1;
	bool OUT_IPGateway_Ack : 1;
	bool OUT_ClearHourMeter_Ack : 1;
	bool OUT_ClearTravelMeter_Ack : 1;

	bool OUT_GyroCorrection_Ack : 1;
	bool OUT_Steer0_Offset_Ack : 1;
	bool OUT_Steer1_Offset_Ack : 1;
	bool OUT_Steer2_Offset_Ack : 1;
	bool OUT_Steer3_Offset_Ack : 1;
	bool OUT_TrackWheel_Offset_Ack : 1;
	bool OUT_TagWrite_Ack : 1;
	bool OUT_MagnetValue_Ack : 1;
};



struct IOMapType
{
	struct PLC_InputType plc_in;
	struct PLC_OutputType plc_out;
	struct SickCPU0_InputType sickcpu0_in;
	struct SickCPU0_OutputType sickcpu0_out;

};


struct IOMapType iomap;

void main ()
{
	iomap.plc_in.BrakeReleased_FrontLeft;
}



#endif






