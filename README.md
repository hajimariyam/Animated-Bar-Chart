# Animated Bar Chart

Animated bar charts spread virally over social media over the past few years because they are a surprisingly simple, yet powerful, way to tell a story about categorical data over time. 

This is a C++ program that generates a text-based animated bar chart for a given data file.

This project suggests the use of a Linux terminal and may not work otherwise.

<img src='https://github.com/hajimariyam/Animated-Bar-Chart/blob/main/gifs/barchartAnimationDark.gif' width='55%' />
<img src='https://github.com/hajimariyam/Animated-Bar-Chart/blob/main/gifs/barchartAnimationLight.gif' width='55%' />

## User Interface
At the onset of the program, the user is prompted to input the filename used for the animation and set a playback rate. The number must be greater than or equal to 0; the greater the number, the slower the animation. Entering a number less than 0 suggests the default playback speed, which is 2.

The appropriate color codes in barchart.h should be used depending on if the terminal is in light or dark mode.

## Data File Format
The data file for the bar chart animation should be in the 'datafiles' folder.
Each file must be organized as a sequence of lines:
- **Line 1:** title of data
- **Line 2:** x-axis label
- **Line 3:** source of data
- **Line 4:** *blank*
- **Onward:** year,name,country,value,category
  - (value is an int, remaining fields are strings without commas or newlines)

Records corresponding to the same year are grouped together. There is an integer n, followed by the n records from that year, sorted by name.
A blank line separates each group.

```
The most populous cities in the world from 1500 to 2018
Population (thousands)
Sources: SEDAC; United Nations; Demographia

12
1500,Beijing,China,672,East Asia
1500,Cairo,Egypt,400,Middle East
1500,Cuttack,India,140,South Asia
1500,Fez,Morocco,130,Middle East
1500,Gauda,India,200,South Asia
1500,Guangzhou,China,150,East Asia
1500,Hangzhou,China,250,East Asia
1500,Istanbul,Turkey,200,Europe
1500,Nanjing,China,147,East Asia
1500,Paris,France,185,Europe
1500,Tabriz,Iran,250,Middle East
1500,Vijayanagar,India,500,South Asia

```

## Sample Data Files
There are a number of fascinating data files in the specified format, curated from various sources.


| **input file** | **description** | **period** | **data source** |
| --- | --- | --- | --- |
| cities.txt | most populous cities in the world | 1500–2018 | [John Burn-Murdoch](https://observablehq.com/@johnburnmurdoch/bar-chart-race-the-most-populous-cities-in-the-world) |
| countries.txt | most populous countries in the world | 1950–2100 | [United Nations](https://population.un.org/wpp/Download/Standard/Population) |
| cities-usa.txt | most populous cities in the U.S. | 1790–2018 | [U.S. Census Bureau](https://factfinder.census.gov/) |
| brands.txt | most valuable brands in the world | 2000–2018 | [Interbrand](https://www.interbrand.com/best-brands/best-global-brands/2018/) |
| movies.txt | highest-grossing movies in the U.S. | 1982–2019 | [Box Office Mojo](https://www.boxofficemojo.com/) |
| baby-names.txt | most popular baby names in the U.S. | 1880–2018 | [U.S. Social Security](https://catalog.data.gov/dataset/baby-names-from-social-security-card-applications-national-level-data) |
| football.txt | best football clubs in Europe | 1960–2019 | [clubelo.com](http://clubelo.com/API) |
| endgame.txt | characters in Endgame by screen time | Minute 1–170 | [Prashant](https://youtu.be/uSj8hMA3lY8) |
| game-of-thrones.txt | characters in Game of Thrones | S01E01–S8E06 | [Jeffrey Lancaster](https://github.com/jeffreylancaster/game-of-thrones) |

