#!/bin/sh

find .. -name "*.lst" | xargs -n1 ./irqgen.py
