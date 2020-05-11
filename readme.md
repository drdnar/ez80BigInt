### BigInt Library

This provides more-or-less optimized unsigned BigInt routines for eZ80 CPUs.
The multiply and divide routines are not very optimized.

Routines currently provided:
* `SetToZero`, `SetToOne`, `SetToNegativeOne`
* `Increment`, `Decrement`
* `Add`, `Subtract`
* `Negate`, `GetSign`
* `IsNonZero`, `IsZero`, `Compare`
* `Multiply`, `Divide`
* `ToStringHex`, `ToString`
* `ShiftLeft`, `ShiftBitInOnLeft`
* `ShiftRight`, `ShiftBitInOnRight`, `SignedShiftRight`
* `GetBit`, `SetBit`

See `src/bigint.h` for full API documentation.

`src/main.c` contains a simple demo program.
