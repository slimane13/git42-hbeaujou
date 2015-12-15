# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    hard_run.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/25 17:26:10 by tfleming          #+#    #+#              #
#    Updated: 2014/12/19 18:20:45 by tfleming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

echo "creating files..."
if [ ! -f "factbook20" ]; then
	cat "factbook" "factbook" "factbook" "factbook" "factbook" "factbook" "factbook" "factbook" "factbook" "factbook" "factbook" "factbook" "factbook" "factbook" "factbook" "factbook" "factbook" "factbook" "factbook" "factbook" > "factbook20"
	cat "factbook20" "factbook20" "factbook20" "factbook20" "factbook20" > "factbook100"
	cat "factbook100" "factbook100" "factbook100" "factbook100" "factbook100" > "factbook500"
	echo "done creating files"
else
	echo "files already created"
fi

time sh run.sh

rm "factbook20"
rm "factbook100"
rm "factbook500"
