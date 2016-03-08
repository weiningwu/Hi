start=`date +%s`

SRC="../ukftractography"

#logFile Name
logFile="log.txt"

# BINARY
BINARY='bin/UKFTractography'

# VOLUME
dwi_path="$SRC/ukf/Data/Input/dwi.nhdr"

# MASK
mask_path="$SRC/ukf/Data/Input/dwi-mask.nhdr"

# SEEDS
seeds_path="$SRC/ukf/Data/Input/seeds_tc.nhdr"

# OUTPUT FIBER
output_path='./seeds_tc.vtk'

eval $BINARY \
 --dwiFile $dwi_path \
 --maskFile $mask_path \
 --tracts $output_path \
 --seedsFile $seeds_path \
 --seedsPerVoxel 5 \
 --numTensor 2 | tee -a $logFile
 end=`date +%s`

runtime=$(python -c "print(${end} - ${start})")
echo "Output file name $output_path" | tee -a $logFile
echo "CPU Runtime was $runtime"  | tee -a $logFile

#diff $output_path $SRC/ukf/Data/Baseline/seeds_tc.vtk