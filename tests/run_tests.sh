#!/bin/bash

echo "=== B-Minor Derleyici Testleri ==="
echo ""

PASS=0
FAIL=0

for test in test*.bminor; do
    result=$(../compiler "$test" 2>&1)
    if echo "$result" | grep -q "Derleme basarili"; then
        echo "✓ $test → GECTI"
        PASS=$((PASS + 1))
    else
        echo "✗ $test → KALDI"
        FAIL=$((FAIL + 1))
    fi
done

echo ""
echo "=== Sonuc: $PASS gecti, $FAIL kaldi ==="