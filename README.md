# poker_odds
Should rename this

The goal is to provide a library that can be used by a front end GUI.
This library started by trying to produce the odds of a player winning a typical game of texas hold 'em poker.
The library has since been gradually expanding on being a full fledged back end to support a game itself.

## To Do
1. Continue working on logic determining winning hands and ties

## Potential Stuff
1. Wrap the library with python bindings
   Leads into 2
2. Create an HTTP Server for interfacing with the library
   This would allow a Web GUI to be created

## Output
Current output ( still working on determining ties )

```
Player ID [ 0 ] WINS [ 406860 ( 37.464 ) ] TIES [ 0 ( 0 ) ] LOSSES [ 679148 ( 62.536 ) ]
Player ID [ 1 ] WINS [ 244148 ( 22.481 ) ] TIES [ 0 ( 0 ) ] LOSSES [ 841860 ( 77.519 ) ]
Player ID [ 2 ] WINS [ 379061 ( 34.904 ) ] TIES [ 0 ( 0 ) ] LOSSES [ 706947 ( 65.096 ) ]
Player ID [ 3 ] WINS [ 55939 ( 5.1509 ) ] TIES [ 0 ( 0 ) ] LOSSES [ 1030069 ( 94.849 ) ]
```