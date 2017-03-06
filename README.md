# ESPMyDoor
## Introduction

I discovered that my intercom was quite easy to hack and that it would be cool if I could open to my roomate who forgot his keys before going to his party.
This is the first use case.
Now let say I'm deeply asleep and I'm not able to open to him. It would be even cooler if he could open the door with his phone !
That's the second use case.

## Hardware

- esp8266-12e
- uart <-> usb programmer (3.3v logic levels !!)

## Software

You can find two files in this project:
- embed.ino which is the code running on the esp
- script.js which contains the web server.

The idea is that you can host the script.js somewhere so it doesn't take space on the tiny memory of the esp :)

## Install
1. Host the script.js on pastebin (for example).
2. Get a minified link with http://bitly.com
3. Replace **[insert bitly script url]**, **[ssid]** and **[password]** in embed.ino
4. Flash the esp with the embed code and install it on your intercom ! :D
