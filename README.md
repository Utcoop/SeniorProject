# SeniorProject
To operate this app you must have
  A SHT25 Temperature and Humidity Sensor 
  An Arduino Uno
  HC-06 Blueooth Module

Once wired you need to upload MIT_SHT25 to the arduino. Ensure that the HC-06 is unplugged when you upload the code as uploading the code sometimes causes errors in the HC-06 module. Open the serial monitor to ensure that data is being taken and is being output in the following format:

time -> Humidity|Temperature
For Example:
12:16:50.961 -> 46.98|22.86 \n
12:16:52.267 -> 46.95|22.88 \n
12:16:53.547 -> 46.88|22.91 \n

Only the values of temperature and humidity are sent by the HC-06
The next step is to get an .apk to your Android smartphone device. This can be done in multiple ways. 

#AIA
Download the .aia to your computer.
Import it to the MIT App Inventor2 to by googling "MIT AI2"  and navigating to your very own projects folder and then import the project.
Open it to see the behind the scenes and locate the build button at the top of the browser. Select "Android App (.apk)
Scan the QR code that will eventually appear to download it straight to your phone, or download it to your computer and transfer it over. 

#APK
Download the .apk file straight out of this github and transfer it to your phone.

Once the APK is on your phone you need to install it. To do this you need to allow unkown apps to be installed. Your phone will most likely think it is unsafe, but I assure you it is.

Once the app is installed pair your HC-06 to your phone throught blueooth settings. If a password is required, whatever depends on who you purchased it from, but the default is "1234". If that doesn't work try "0000".

Once paired simply open the app, select the bluetooth icon in the top left and select the HC-06 and begin your data collection!
