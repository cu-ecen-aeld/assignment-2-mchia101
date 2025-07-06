#!/bin/bash
# assigment 1 for finder.sh
# Author: mchia101

# stop while executing the script if any command fails
set -e
#stop while executing the script if any variable is not set
set -u


if [ $# -lt 2 ]
then
    echo "Usage: $0 <directory> <string>"
    exit 1
else
    DIRECTORY=$1
    SEARCH_STRING=$2
fi

# Redirect stderr and stdout to /dev/null to avoid printing errors if the directory does not exist
if ! find "$DIRECTORY" >/dev/null 2>&1;
then
#print an error message and exit with status 1
    echo "Directory $DIRECTORY does not exist."
    exit 1
else
    # Count the number of files in the directory
    NUM_FILES=$(find "$DIRECTORY" -type f | wc -l)
    #  Count the number of matching str in each file and use wc to sum the total count 
    NUM_STR_MATCH=$(find "$DIRECTORY" -type f | xargs grep -o "$SEARCH_STRING" | wc -l)
    echo "The number of files are $NUM_FILES and the number of matching lines are $NUM_STR_MATCH"
fi







