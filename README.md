## CLI-TIL
A Simple program that can show facts from a few online sources

Currently for Linux Only

### Building
* Fetch dependencies (`json11`) by running `git submodule update --init`
* run `make`
* run `make test`

### Options
* Source to fetch from is passed in as a command line parameter, eg: `./clitil numbers`
* Available source are:
    * `reddit` for [/r/TodayILearned](https://www.reddit.com/r/todayilearned/) - top post of the day
    * `numbers` for the [NumbersAPI](http://numbersapi.com) - fact about a random year
    * `icndb` for [ICNDB](http://www.icndb.com/) - random Chuck Norris joke
