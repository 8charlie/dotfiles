#!/bin/bash

# Get the volume percentage
VOLUME=$(pactl list sinks | grep '^[[:space:]]Volume:' | \
          head -n 1 | awk '{print $5}' | sed 's/%//')

# Print the volume percentage
echo "Volume: ${VOLUME}%"

