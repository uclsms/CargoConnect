

// This mission does the stuff in the center of the board  (Truck drop off, slip roads down)
void centerMission()
{

	// Reset the gyroscoe and wait 100ms to settle
	resetGyro(gyro);
	sleep(200);

	driveStraightGyroDistance(20, 2, 0, false);
	driveStraightGyroDistance(50, 10, 0, true);

	sideTurnUsingGyro(20, 45, false);



}


// This does the missions on the south wall.  (Door Deliver, Package Drop off)
/*void southWallMission()

{
	driveStraightGyroDistance(20,38,0,false);

	centerTurnUsingGyro(20,45,false);

	driveStraightGyroDistance(20,6,0,false);

	centerTurnUsingGyro(20,-35,false);

	driveStraightGyroDistance(20,12,0,false);

	centerTurnUsingGyro(20,-45,false);

	moveLeftAttachmentMotorDegrees(20,-200,false);

	driveStraightGyroDistance(20,-3,0,false);

	centerTurnUsingGyro(20,45,false);

	driveStraightGyroDistance(20,-10,0,false);

	centerTurnUsingGyro(20,-45,false);

	driveStraightGyroDistance(20,-40,0,false);















}
*/


// South Wall Pt2 (gyro was drifting to much)
void southWallMission ()
{
 	// go forward 43 inches
	driveEncoderDistance (30,30,43,true);

  sideTurnUsingGyro(30,45,true);

  driveEncoderDistance(30,30,10,true);

  sideTurnUsingGyro(30,-45,true);

  moveLeftAttachmentMotorDegrees(10,-200,false);

  sideTurnUsingGyro(20,20,true);

  driveEncoderDistance(-30,-30,5,true);


//  driveEncoderDistance(30,30,10,true);

//  sideTurnUsingGyro(30,-45,true);

//  driveEncoderDistance(30,30,40,true);






























}

// This does the missions on the east wall (Hellicopter, Cargo Ship)
void eastWallMission()
{
driveStraightGyroDistance(30,24,0,true);
centerTurnUsingGyro(25,90,true);
driveEncoderDistance(50,50,20,true);
lineFollowForDistance(30,5,rightSensor,rightEdge,true);
lineFollowUntilLine(20,leftSensor,leftEdge,white,true);


}

// This mission does the end mission
void endMission()
{


}





















//----------------------------------------------------------------------------------------------------
// Name:northWallMission
//----------------------------------------------------------------------------------------------------
// Description:
//----------------------------------------------------------------------------------------------------
//Inputs: None
//----------------------------------------------------------------------------------------------------
void northWallMission()
{

	sleep(500);

	// Reset the gyroscoe and wait 100ms to settle
	resetGyro(gyro);

	sleep(200);

	// Drive straight using the gyro to get on top of the line to follow
	// driveStraightGyroDistance(30, 27.5, -2, true);
	driveStraightEncoderDistance(30, 26.5, true);

	// Turn using the gyro to get close and not get stuck on the yellow line
	sideTurnUsingGyro(10, 20, true);

	// Turn to the right until we see white.
	sideTurnUntilLine(10, rightSensor, white, true);

	// Turn to the right until we see black.
	sideTurnUntilLine(10, rightSensor, black, true);

	// Turn to the right until we see white.
	sideTurnUntilLine(10, rightSensor, grey, true);


	lineFollowUntilLine(10,rightSensor,rightEdge,white,true);

	lineFollowUntilLine(10,rightSensor,rightEdge,black,true);

	moveRightAttachmentMotorDegrees(100,600,false);

	sleep(500);

	moveRightAttachmentMotorDegrees(100,-600,false);

	driveStraightEncoderDistance(15, 6.7, true);

	moveLeftAttachmentMotorDegrees(50,-280,false);

	centerTurnUsingGyro(10, 45, true);

	moveLeftAttachmentMotorDegrees(10,200,false);

	driveForTime(-30,-30,1.2);

	centerTurnUsingGyro(20, 120, true);

	driveForTime(75,75,1.5);

	setBrakeMode(false);

}

//----------------------------------------------------------------------------------------------------
// Name:blueBox
//----------------------------------------------------------------------------------------------------
// Description:
//----------------------------------------------------------------------------------------------------
//Inputs: None
//----------------------------------------------------------------------------------------------------

void blueBoxMission()
{

	// Reset the gyroscoe and wait 100ms to settle
	resetGyro(gyro);
	sleep(200);

	driveStraightGyroDistance(20, 2, 0, false);
	driveStraightGyroDistance(50, 18, 0, true);

	sideTurnUsingGyro(20, -90, false);


	driveStraightEncoderDistance(60,10,false);


}
