#!/bin/sh

find .. -name "*.lst" | tee /dev/stderr | xargs -n1 ./irqgen.py
