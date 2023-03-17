# JSONSki vs simdjson
This repository contains experiments to compare the performance of JSONSki against that of simdjson.

The `.cpp` files in this repository use `bestbuy_large_record.json` from this [link](https://drive.google.com/drive/folders/1KQ1DjvIWpHikOg1JgmjlSWM3aAlvq-h7)

### Experiment 1(a)
The files `jsonski_forsingle.cpp` and `simdjson_forsingle.cpp` are used to compare the performance of the two parsers when attempting to parse a single JSON instance using the on-demand parser for simdjson.

Here are the results for this:

<img width="615" alt="Capture9" src="https://user-images.githubusercontent.com/31547103/224582035-17896306-f55e-43b9-93e1-ecb298d77bf0.PNG">

### Experiment 1(b)
The files `jsonski_forslice.cpp` and `simdjson_forslice.cpp` are used to compare the performance of the two parsers when attempting to parse a sequence of contiguous JSON instances using a loop by utilizing the on-demand parser for simdjson.

Here are the results for this:

<img width="952" alt="Capture10" src="https://user-images.githubusercontent.com/31547103/224582079-6b95e451-be1a-42c0-84bb-f39637c96034.PNG">

These experiments using the on-demand parser show that JSONSki is around 5 to 6 times faster than simdjson.

### Experiment 2(a)
The files `jsonski_forsingle.cpp` and `simdjson_dom_single.cpp` are used to compare the performance of the two parsers when attempting to parse a single JSON instance using the DOM parser for simdjson.

Here are the results for this:

<img width="767" alt="Capture12" src="https://user-images.githubusercontent.com/31547103/225524372-21f3bc48-0b72-4c12-8b61-d442a7990933.PNG">

### Experiment 2(b)
The files `jsonski_forslice.cpp` and `simdjson_dom_slice.cpp` are used to compare the performance of the two parsers when attempting to parse a sequence of contiguous JSON instances using a loop by utilizing the DOM parser for simdjson.

Here are the results for this:

<img width="957" alt="Capture11" src="https://user-images.githubusercontent.com/31547103/225524548-78696c61-e1b0-49f9-861e-866a393aed13.PNG">

These experiments using the DOM parser show that JSONSki is around 11 to 12 times faster than simdjson.
