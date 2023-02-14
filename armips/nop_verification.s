.nds
.thumb


.definelabel NEW_CHANGES, 0


.open "build/data/weather_sys.narc_65", 0x023C8000

// mikelan's checksum verification routine that ensures we load an unmodified synthetic overlay.  appears to just fuck the stack if it fails
.org 0x023CDBB8

.ifdef NEW_CHANGES
bx lr
.else
push {r3, lr}
.endif // NEW_CHANGES


.close
