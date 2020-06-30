class image {
public:
    image (int width, int height){
        width_ = width;
        height_ = height;
        pixels_ = std::vector<bool>(width * height);
    }

    void set_pixel(int x, int y, bool color){
        pixels_[ y * width_ + x ] = color;
    }
    bool get_pixel(int x, int y){
        return pixels_[y * width_ + x];
    }

    int width() { return width_; }
    int height() { return height_; }

private:

    int width_;
    int height_;
    std::vector<bool> pixels_;
};

void save_to_ppm(image& img, std::string filename){
    std::fstream out(filename, std::ios::out);
    out << "P1\n" << img.width() << ' ' << img.height() << '\n';

    for (int y=0; y < img.height(); ++y){
        for (int x = 0; x < img.width(); ++x){
            out << img.get_pixel(x, y) << ' ';
        }
        out << "\n";
    }
}