/*
Copyright 2018 Jacques de Hooge, GEATEC engineering, www.geatec.com

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

/*
This program features 2 statemachines.
One has 2 states, the other 3.
They each run at their own pace.

Note that state machines don't have to cycle through a fixed sequence of states.
They can go through states in arbitrary, dynamically determined order.
Also state transitions do not need to be triggered by elapsed time intervals.
The may also be caused by external triggers, like sensor signals changing.
*/

#include <stdio.h>
#include <stdbool.h>

#define offBlinkState 0
#define onBlinkState 1

#define greenPhaseState 0
#define yellowPhaseState 1
#define redPhaseState 2

void delay (float seconds) { // Expensive, somewhat portable hack...
  float const environmentDependentFactor = 2e8;
  for (int step = 0; step < seconds * environmentDependentFactor; step++);
}

int main () {

    // ====== Yellow blinking traffic light
    
    int const blinkTime = 3000;
    
    int oldBlinkState = onBlinkState;
    int blinkState = offBlinkState;
    
    bool yellowBlinkLightIsOn = false;
    
    // ====== Green, yellow and red phase traffic light
    
    int const phaseTime = 2000;
    
    int oldPhaseState = redPhaseState;
    int phaseState = greenPhaseState;
    
    bool greenPhaseLightIsOn = false;
    bool yellowPhaseLightIsOn = false;
    bool redPhaseLightIsOn = false;
    
    // ====== Initialize start time
    
    int currentTime = 0;
    int startBlinkTime = currentTime;
    int startPhaseTime = startBlinkTime;
        
    // ====== Main control loop
    
    printf ("State machines: No SLEEP but ASYNCH!\n");
    printf ("(Press [ENTER] each time to advance 1 s)\n\n");
    
    while (true) {
        // ====== Read out clock only once in the main loop, so there's only one unique time

        // In a realtime environment, the current system time would be retrieved
        currentTime += 100;
        
        // ====== Separate state machine for blinking traffic light, has 2 phases
        
        switch (blinkState) {
            case offBlinkState:
                if (blinkState != oldBlinkState) {
                    // This part only done once after state transition
                    oldBlinkState = blinkState;
                }
                
                // Transition condition continuously monitored
                if (currentTime - startBlinkTime > blinkTime) {
                    blinkState = onBlinkState;
                }
                
                break;
                
            case onBlinkState:
                if (blinkState != oldBlinkState) {
                    // This part only done once after state transition
                    oldBlinkState = blinkState;
                    yellowBlinkLightIsOn = true;
                }
                
                // Transition condition continuously monitored
                if (currentTime - startBlinkTime > 2 * blinkTime) {
                    blinkState = offBlinkState;
                    startBlinkTime = currentTime;             
                    yellowBlinkLightIsOn = false;
                }
                
                break;
        }
    
        // ====== Separate state machine for red, green, yellow phase traffic light, has 3 phases
        
        switch (phaseState) {
            case greenPhaseState:
                if (phaseState != oldPhaseState) {
                    // This part only done once after state transition   
                    oldPhaseState = phaseState;
                    greenPhaseLightIsOn = true;
                }
                
                // Transition condition continuously monitored
                if (currentTime - startPhaseTime > 2 * phaseTime) {
                    phaseState = yellowPhaseState;
                    greenPhaseLightIsOn = false;
                }
                
                break;
                
            case yellowPhaseState:
                if (phaseState != oldPhaseState) {
                    // This part only done once after state transition   
                    oldPhaseState = phaseState;
                    yellowPhaseLightIsOn = true;
                }
                
                // Transition condition continuously monitored
                if (currentTime - startPhaseTime > 3 * phaseTime) {
                    phaseState = redPhaseState;
                    yellowPhaseLightIsOn = false;
                }
                
                break;
                
            case redPhaseState:
                if (phaseState != oldPhaseState) {
                    // This part only done once after state transition   
                    oldPhaseState = phaseState;
                    redPhaseLightIsOn = true;
                }
                
                // Transition condition continuously monitored
                if (currentTime - startPhaseTime > 5 * phaseTime) {
                    phaseState = greenPhaseState;
                    startPhaseTime = currentTime;
                    redPhaseLightIsOn = false;
                }
                
                break;
        }
 
        if (currentTime % 1000 == 0) {
            printf ("%3i s      %c      %c %c %c\n", currentTime / 1000, yellowBlinkLightIsOn ? 'B' : '.', greenPhaseLightIsOn ? 'G' : '.', yellowPhaseLightIsOn ? 'Y' : '.', redPhaseLightIsOn ? 'R' : '.');
            delay (1);
        }
    }
    return 0;
}
