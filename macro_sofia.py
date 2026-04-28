from ij import IJ

# Process images 1 through 7
for i in range(1, 8):
    # 1. Open the image
    source_path = "C:/Users/Storm trooper/Desktop/5_Originales/golgi_cox_10x_stack_%d.czi" % i
    IJ.open(source_path)

    # 2. Select the image
    IJ.selectWindow("golgi_cox_10x_stack_%d.czi" % i)

    # 3. Save as TIFF in Originales
    tiff_path = "C:/Users/Storm trooper/Desktop/5_Originales/golgi_cox_10x_stack_%d.tif" % i
    IJ.saveAs("Tiff", tiff_path)

    # 4. Apply Unsharp Mask filter
    IJ.run("Unsharp Mask...", "radius=1 mask=0.60")

    # 5. Save processed version in Analisis
    dest_path = "C:/Users/Storm trooper/Desktop/5_Analisis/golgi_cox_10x_stack_%d_unsharp.tif" % i
    IJ.saveAs("Tiff", dest_path)

    # 6. Close the image window
    IJ.getImage().close()
