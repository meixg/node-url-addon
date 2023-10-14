{
  "targets": [
    {
      "target_name": "url",
      "sources": [
        "src/index.cc",
        "src/url.cc"
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