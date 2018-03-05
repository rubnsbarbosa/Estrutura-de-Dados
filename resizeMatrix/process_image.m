function [img] = process_image(img)

decimation = 2;

%img = imread(imgPath);

yIndices = 1:decimation:size(img, 1);
xIndices = 1:decimation:size(img, 2);

img = img(yIndices, xIndices);

end
