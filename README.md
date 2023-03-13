# JSONSki vs simdjson
This repository contains experiments to compare the performance of JSONSki against that of simdjson.

The `.cpp` files in this repository use `bestbuy_large_record.json` from this [link](https://drive.google.com/drive/folders/1KQ1DjvIWpHikOg1JgmjlSWM3aAlvq-h7)

The files `jsonski_forsingle.cpp` and `simdjson_forsingle.cpp` are used to compare the performance of the two parsers when attempting to parse a single JSON instance.

Here are the results for this:

<img width="615" alt="Capture9" src="https://user-images.githubusercontent.com/31547103/224582035-17896306-f55e-43b9-93e1-ecb298d77bf0.PNG">

The files `jsonski_forslice.cpp` and `simdjson_forslice.cpp` are used to compare the performance of the two parsers when attempting to parse a sequence of contiguous JSON instances using a loop.

Here are the results for this:

<img width="952" alt="Capture10" src="https://user-images.githubusercontent.com/31547103/224582079-6b95e451-be1a-42c0-84bb-f39637c96034.PNG">

These experiments show that JSONSki is around 5 to 6 times faster than simdjson.
