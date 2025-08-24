#!/bin/bash
osascript -e 'tell application "System Events" to click (button 1 of (every window of (first process whose frontmost is true)))'

