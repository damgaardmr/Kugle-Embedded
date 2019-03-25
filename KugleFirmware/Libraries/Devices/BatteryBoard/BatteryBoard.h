/* Copyright (C) 2018-2019 Malte R. Damgaard. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the MIT License
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the MIT License for further details.
 *
 * Contact information
 * ------------------------------------------
 * Malte R. Damgaard
 * e-mail   :  DamgaardMR@gmail.com
 * ------------------------------------------
 */
 
#ifndef DEVICES_BATTERYBOARD_H
#define DEVICES_BATTERYBOARD_H

#include "SMBus.h"

class BatteryBoard
{

public:
	BatteryBoard(SMBus::port_t SMBusHardwareResources, uint16_t _chargerCurrentLimit);
	~BatteryBoard();
	void SetCurrentLimitRAM(uint16_t LimitmA);
	void SetCurrentLimitEEPROM(uint16_t LimitmA);

private:
	static void BatteryBoardRAMThread(void * pvParameters);
	static void BatteryBoardEEPROMThread(void * pvParameters);
	bool SetCurrentLimitRAM();
	bool SetCurrentLimitEEPROM();
	void SetChargeCurrentLimit(uint16_t LimitmA, uint8_t configuration);
	void SetInputCurrentLimit(uint16_t LimitmA, uint8_t configuration);

	SMBus * smbus;
	uint16_t chargerCurrentLimit; // mA
	uint16_t currentLimitEEPROM;
	uint16_t currentLimitRAM;
	uint8_t DeviceAddr = 0x10;

	// task params
	const uint32_t BATTERY_BOARD_THREAD_STACK = 256;

	TaskHandle_t batteryBoardRamTaskHandle;
	TaskHandle_t batteryBoardEepromTaskHandle;

	class CmdAddr
	{
	public:
		class read{
		public:
			enum : uint8_t
			{ // according to smbus protocol v 1.1
				ManufacturerAccess = 0x00,
				RemainingCapacityAlarm,
				RemainingTimeAlarm,
				BatteryMode
				// 0x25 - 0x2e reserved
				// 0x2f OptionalMfgFunction5
				// 0x30 - 0x3b reserved
				// 0x3c - 0x3f OptionalMfgFunction4-1
			};
		};

		class write{
		public:
			enum : uint8_t
			{ // according to smbus protocol v 1.1
				ChargerMode = 0x12,
				ChargingCurrent = 0x14,
				ChargingVoltage,
				AlarmWarning,
				SelectorPresets = 0x22,
				// 0x3c - 0x3f OptionalMfgFunction4-1
				// PMM240 specific commands...
				SetChargeCurrentLimit = 0x3C,
				SetInputCurrentLimit = 0x3D,
			};
		};
	};
	
	class configuration{
	public:
		enum : uint8_t
		{ // according to smbus protocol v 1.1
			RAM = 0x00,
			EEPROM = 0x01
		};
	};

};
	
	
#endif
