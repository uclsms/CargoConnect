#pragma config(Sensor, S1,     leftColor,      sensorEV3_Color)
#pragma config(Sensor, S2,     attachmentColor, sensorEV3_Color)
#pragma config(Sensor, S3,     gyro,           sensorEV3_Gyro)
#pragma config(Sensor, S4,     rightColor,     sensorEV3_Color)
#pragma config(Motor,  motorA,          leftAttachment, tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          rightDrive,    tmotorEV3_Large, PIDControl, reversed, driveRight, encoder)
#pragma config(Motor,  motorC,          leftDrive,     tmotorEV3_Large, PIDControl, reversed, driveLeft, encoder)
#pragma config(Motor,  motorD,          rightAttachment, tmotorEV3_Medium, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//



// Global Variables - These can be used anywhere in any function.  They are global in scope.
// These need to be before the include functions so that they can be defined before the compiler wants to use them.
float wheelDiameterInMM;
int reflectedLightIntensityOnBlack;
int reflectedLightIntensityOnWhite;
float widthBetweenWheelsInMM;
bool forwardMotorMovementIsPositive;

// Define variables to pass into functions to not have to use pointers.
string leftSensor;
string rightSensor;
string leftEdge;
string rightEdge;
string black;
string grey;
string white;


// Files to Include
#include "MiscDriveFunctions.C"
#include "GyroDriveFunctions.C"
#include "EncoderDriveFunctions.C"
#include "EncoderTurnFunctions.C"
#include "LineFollowingFunctions.C"
#include "Missions.C"
#include "SetupGlobalVariables.C"


void displayMissionName(int missionIndex)
{
	// 0 = North Wall Mission
	// 1 = Center Mission
	// 2 = South Wall Mission
	// 3 = East Wall Mission
	// 4 = End Mission


	if (missionIndex == 0) displayCenteredBigTextLine(2, "Blue Box" );
	if (missionIndex == 1) displayCenteredBigTextLine(2, "North Wall" );
	if (missionIndex == 2) displayCenteredBigTextLine(2, "Center" );
	if (missionIndex == 3) displayCenteredBigTextLine(2, "South Wall" );
	if (missionIndex == 4) displayCenteredBigTextLine(2, "East Wall" );
	if (missionIndex == 5) displayCenteredBigTextLine(2, "End" );
	if (missionIndex == 6) displayCenteredBigTextLine(2, "Clean Wheels" );


}


task main()
{

	// Setup Global Variables
	setupGlobalVariables();

	// Reset the gyro when the program starts
	resetGyro(gyro);


	// Setting up initial values and display
	int missionIndex;
	missionIndex = 0;
	displayMissionName(missionIndex);

	// Set the volumne to low
	setSoundVolume(10);

	//Loop to run selector program
	while(true)                   // infinite loop:
	{

		//While the left button (5) is pressed
		if ((getButtonPress(buttonLeft) == 1) && missionIndex > 0)
		{

			missionIndex = missionIndex - 1;
			displayMissionName(missionIndex);
			playSound(soundBlip);
			sleep (250);

		}
		else if(getButtonPress(buttonRight) == 1 && missionIndex < 6)
		{

			missionIndex = missionIndex + 1;
			displayMissionName(missionIndex);
			playSound(soundBlip);
			sleep (250);

		}

		// Display The Gyro
		displayCenteredBigTextLine(6, "Gyro: %d", getGyroDegrees(gyro) );



		if (getButtonPress(buttonEnter) == 1)
		{

			if (missionIndex == 0) blueBoxMission();
			if (missionIndex == 1) northWallMission();
			if (missionIndex == 2) centerMission();
			if (missionIndex == 3) southWallMission();
			if (missionIndex == 4) eastWallMission();
			if (missionIndex == 5) endMission();
			if (missionIndex == 6) cleanWheels();

		}

	}

}
