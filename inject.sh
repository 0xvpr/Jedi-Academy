#!/bin/bash

# Creator: VPR
# Created: December 14th, 2021
# Updated: December 24th, 2021

# This script is intended to work with Pidjeon for a seamless injection process.

TARGET="jasp.exe"               # Change as necessary
PAYLOAD="Bin/Payload.dll"       # Change as necessary
PIDJEON_PATH="${HOME}/.toolkit"   # Change as necessary

export PATH=$PATH:"${PIDJEON_PATH}"

function inject {
    pidjeon_x86.exe "${TARGET}" "${PAYLOAD}"
}

inject
