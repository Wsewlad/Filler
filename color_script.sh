lblue=$(printf "\e[94mO\e[0m")
lgray=$(printf "\e[37mX\e[0m")
white=$(printf "\e[97mo\e[0m")
lyel=$(printf "\e[93mx\e[0m")
dark=$(printf "\e[90m\.\e[0m")

sed "s|O|$lblue|g" |
sed "s|X|$lgray|g" |
sed "s|x|$lyel|g" |
sed "s|\.|$dark|g" |
sed "/^0.. /s|o|$white|g" |
sed "s|fin|player|g"