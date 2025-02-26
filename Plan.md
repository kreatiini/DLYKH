# Plan

## So how are we going to approach this problem and what issues may arise during the process?

### Parts used in the initial plan:
1. Arduino UNO R4 Wifi - The base for this project. Everything will be connected to the Arduino.
2. RFID Reader and a keytag - Recongnizing if the keys are in place or not
3. A closed circuit magnetic door switch - Recognizing if the door is open or closed
4. A buzzer - Alerting when the door is open and keys are in place
5. A button - To add a delay if you just open the door without going out and turn off the counter

### How will it work?
- When you place your keys on the RFID reader the Arduino will know if the keys are there or not.
- If the keys are in the tray and you open the door, the buzzer will make an alert
- If the keys are not in the tray while the door opens, there will be no alert
- To avoid making the alert when you get home there will be a counter. Maybe like odd numbers the door will alert and even numbers it wont alert. The counter will reset after certain number has reached so it wont reach too big count.
- To avoid making an alert when opening the door when letting someone in for example, the button will pause the counter and the alert for specific time. Maybe like 60 or 120 seconds. 

## Schedule

### Week 1 (week number 5)
- Refining the project plan and idea
### Week 2 (week number 6)
- Choosing the project
- Making the project plan
- Ordering the parts needed
- Creating project presentation
- Choosing where and how to document the project
### Week 3 (week number 7)
- Researching and learning the parts
- Group meeting
- Searching additional information needed for the project
### Week 4 ( week number 8)
- Last stage of learning about the parts
- Choosing the correct ways to connect the parts
- Connecting the RFID Reader to the Arduino
### Week 5 (week number 9)
- Programming the RFID Reader and keytag
- Testing the RFID reader
### Week 6(week number 10)
- Connecting the door switch to the Arduino
- Programming the door switch
### Week 7 (week number 11)
- Testing the door switch
- Connecting the buzzer to the Arduino
- Connecting the button to the Arduino
### Week 8 (week number 12)
- Programming the buzzer and the button
- Testing the buzzer and the button
### Week 9 (week number 13)
- Testing phase
### Week 10 (week number 14) to Week 14(week number 18)
- Testing the whole project
- Refining the details
- Fixing problems that may arise
- Finishing the documentation
