# seven_segment_display
Simple seven segment display project running in Renode.

## Dependancies
### Renode
https://github.com/renode/renode

### arm-none-eabi-gcc
https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads

## Build
-- cmake -B build
-- cmake --build build --target run_in_renode
-- open localhost:8000 in browser