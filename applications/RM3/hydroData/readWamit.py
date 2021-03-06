
from bemio.io import wamit as wio
from bemio.data_structures import bem as hd
import matplotlib.pyplot as plt
plt.close('all')
plt.interactive(True)

# Load the data
w = wio.WamitOutput(out_file='rm3_new.out')

print w.data[0].num_bodies

# Calculate IRF and plot
for i in xrange(w.data[0].num_bodies):
	w.data[i].calc_irf()
#	w.data[i].calc_ss()
	w.data[i].plot_irf([[0,0],[2,2]]	)
	w.data[i].plot_am_rd([[0,0],[2,2]])

# Save the data in HDF5 format
hd.write_hdf5(w)
