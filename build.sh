#!/usr/bin/env bash
# Fetch the latest version of the library
fetch() {
if [ -d "clay" ]; then return; fi
URL="https://github.com/nicbarker/clay/archive/refs/heads/main.zip"
ZIP="${URL##*/}"
DIR="clay-main"
mkdir -p .build
cd .build

# Download the release
if [ ! -f "$ZIP" ]; then
  echo "Downloading $ZIP from $URL ..."
  curl -L "$URL" -o "$ZIP"
  echo ""
fi

# Unzip the release
if [ ! -d "$DIR" ]; then
  echo "Unzipping $ZIP to .build/$DIR ..."
  cp "$ZIP" "$ZIP.bak"
  unzip -q "$ZIP"
  rm "$ZIP"
  mv "$ZIP.bak" "$ZIP"
  echo ""
fi
cd ..

# Copy the libs to the package directory
echo "Copying libs to clay/ ..."
rm -rf clay
mkdir -p clay
cp -f  ".build/$DIR/clay.h" clay/
cp -rf ".build/$DIR/renderers" clay/
echo ""
}


# Test the project
test() {
echo "Running 01-win32_gdi.c ..."
clang -I. -o 01.exe examples/01-win32_gdi.c  && ./01.exe && echo -e "\n"
}


# Main script
if [[ "$1" == "test" ]]; then test
elif [[ "$1" == "fetch" ]]; then fetch
else echo "Usage: $0 {fetch|test}"; fi
