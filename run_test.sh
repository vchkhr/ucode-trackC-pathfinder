./pathfinder test/$1 > temp
diff temp test/$1_correct > correct

if cat correct | grep -q '>'
then echo 'NOT PASSED'
else echo 'PASSED'
fi

rm correct
rm temp
