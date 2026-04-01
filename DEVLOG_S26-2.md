# Developer Log (DEVLOG.md)
## Monopoly Board Simulator (Spring 2026)

Minimum **6 entries** required.

Each entry must document learning and reasoning. Fabricated bugs are not expected.

---

## Allowed Entry Types
Each entry may be one of the following:

1) **Bug Fix Entry**
- The issue encountered.
- Error messages or symptoms.
- Attempts made.
- Final resolution.

2) **Edge Case / Testing Entry**
- A failure discovered through testing.
- The specific input/state that caused it.
- The change you made to handle it correctly.

3) **Engineering Decision Entry (up to 2 allowed)**
- A design decision you made.
- An alternative approach you considered.
- Why you chose one approach over another (tradeoffs).

---

### Entry 1
**Date:** 2026-03-31  
**Entry Type:** Bug Fix
**Task worked on:**  Tokenize
**Issue or decision:**  Would not push into vector
**Error message / symptom (if applicable):**  error: expected expression
**What I tried:**  I tried to convert to different types of data such as string
**Fix / resolution (or final decision):**  Making individual tokens for each time I wanted to push into the vector
**Commit(s):**  Fixed Tokenize pushing actual Token

---

### Entry 2
**Date:** 2026-03-31  
**Entry Type:** Edge Case  
**Task worked on:**  Tokenize
**Issue or decision:**  Created a new if statement after the loop to push any last numbers
**Error message / symptom (if applicable):**  
**What I tried:**  Before if there were numbers at the end since it only pushes after a non number the last would not push
**Fix / resolution (or final decision):**  New if statement after the loop to push numbers
**Commit(s):**  Edge case for when last value in line is a number

---

### Entry 3
**Date:** 2026-03-31  
**Entry Type:** Edge Case  
**Task worked on:**  ArrayStack
**Issue or decision:**  Trying to pop on an empty stack results in error
**Error message / symptom (if applicable):**  
**What I tried:**  Originally had just data.pop_back()
**Fix / resolution (or final decision):**  Create an exemption to throw runtime error when data is empty and pop is called
**Commit(s):**  Implemented ArrayStack methods

---

### Entry 4
**Date:** 2026-03-31  
**Entry Type:** Engineering Decision  
**Task worked on:**  isValidInfix
**Issue or decision:**  Created a bool check and change check to check whether op or num was expected
**Error message / symptom (if applicable):**  
**What I tried:**  Checking twice for parenthesis and op or num 
**Fix / resolution (or final decision):**  Separated each condition for infix
**Commit(s):**  Implemented isValidInfix

---

### Entry 5
**Date:** 2026-03-31  
**Entry Type:** Bug Fix 
**Task worked on:**  Fixing isValidPostfix
**Issue or decision:**  I checked whether it should be an operator or number with the int count
**Error message / symptom (if applicable):**  Example 2 (3+4*2) results in a postfix
**What I tried:**  I checked with if the token is an operator I would remove a count and expect a number
**Fix / resolution (or final decision):**  Make it not a valid postfix if it's an operator after an operator and return false earlier
**Commit(s):**  Fixed isValidPostfix

---

### Entry 6
**Date:** 2026-03-31  
**Entry Type:** Engineering Decision  
**Task worked on:**  evalPostfix
**Issue or decision:**  Check through each possible operation and push the result into the stack
**Error message / symptom (if applicable):**  
**What I tried:**  Iterating through and applying each operation
**Fix / resolution (or final decision):**  Use the stack to push and treat each operation as a token which goes into the stack and after push remaining
**Commit(s):**  Fixed precedence, implemented evalPostfix
