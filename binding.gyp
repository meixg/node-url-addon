{
  "targets": [
    {
      "target_name": "url",
      "sources": [
        "src/index.cc",
        "src/url.cc",
        "src/search_params.cc",
        "src/deps/ada/ada.cc",
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ],
      "cflags_cc": [
        "-std=c++17",
      ]
    }
  ]
}