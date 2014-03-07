/*
 * Copyright 2011 Phidgets Inc.  All rights reserved.
 */

import java.io.IOException;

import com.phidgets.PhidgetException;
import com.phidgets.StepperPhidget;
import com.phidgets.event.ErrorEvent;
import com.phidgets.event.ErrorListener;
import com.phidgets.event.StepperPositionChangeEvent;
import com.phidgets.event.StepperPositionChangeListener;

public class StepperExample {

	static StepperPhidget b;

	public static void main(String[] args) throws InterruptedException {
		ErrorListener ErrorListener = null;
		StepperPositionChangeListener StepperPositionChangeListener = null;

		int i;

		try {
			try {
				b = new StepperPhidget();

				b.openAny();
				System.out
						.println("Waiting for the Phidget Stepper to be attached...");
				b.waitForAttachment();

				b.addErrorListener(new ErrorListener() {

					public void error(ErrorEvent ex) {
						System.out.println("\n--->Error: " + ex.getException());
					}
				});

				b.addStepperPositionChangeListener(new StepperPositionChangeListener() {

					public void stepperPositionChanged(
							StepperPositionChangeEvent spce) {
						// System.out.println(spce.toString());
					}
				});

				System.out.println("Phidget Information");
				System.out.println("====================================");
				System.out.println("Version: " + b.getDeviceVersion());
				System.out.println("Name: " + b.getDeviceName());
				System.out.println("Serial #: " + b.getSerialNumber());
				System.out.println("# Steppers: " + b.getMotorCount());

				Thread.sleep(100);

				System.out.println("\nInitializing");
				for (i = 0; i < b.getMotorCount(); i++) {

					// Set up some initial acceleration and velocity values
					// double minAccel = b.getAccelerationMin(i);
					b.setAcceleration(i, 300000);
					// double maxVel = b.getVelocityMax(i);
					b.setVelocityLimit(i, 250000);
					b.setCurrentLimit(i, 1.5);

					try {
						System.out.println("\nMotor: " + i + " at Position: "
								+ b.getCurrentPosition(i));
					} catch (PhidgetException ex) {
						System.out.println("Exception: " + "Phidget Error: "
								+ ex.getDescription());
					}

					System.out.println("\nEngaging Stepper Motor: " + i + "\n");
					b.setEngaged(i, true);
				}

				System.out.println("\nSetting Target Positions to 200\n");
				for (i = 0; i < b.getMotorCount(); i++) {
					b.setTargetPosition(i, 318000);
					Thread.sleep(1000);
					b.setCurrentPosition(i, 0);

				}

				System.out.print("\n\nPress any key to close...\n\n");

				System.in.read();
			} catch (IOException ex) {
			}

			System.out.println("Disengaging Stepper Motors");
			for (i = 0; i < b.getMotorCount(); i++) {

				b.setEngaged(i, false);
			}

			// closing

			b.removeStepperPositionChangeListener(StepperPositionChangeListener);
			b.removeErrorListener(ErrorListener);

			b.close();
			b = null;
			System.out.println("\nTurning off Phidget Stepper");

		} catch (PhidgetException ex) {
			System.out.println("Exception: " + "Phidget Error: "
					+ ex.getDescription());
		}
	}
}
