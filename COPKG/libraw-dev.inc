@import "version.inc" ;
@import "outercurve.inc" ;

package {
    name: "libraw-dev[${flavor}]";
    version: "${package-version}";
    arch : "${arch}";

    display-name: "libraw Developer library";
}

metadata {
    summary: "The libraw developer library";
    description: @"Library for reading and processing of RAW digicam images"; 

    icon: @"libraw.png";
    
    author-version : "0.14.5";
    bug-tracker: "https://github.com/coapp-packages/libraw/issues";
    stability : "0";
    licenses : {
        LGPL
    };
}

files[libs] {
    root: @"..\output\vc10\${arch}\release\bin";
    
    include: {
        "*.lib"
    };
    
    trim-path: all;
};

requires {
    package: "libraw-dev-common-${package-version}-any-${Package.PublicKeyToken}";
    package: "libraw[${flavor}]-${package-version}-${Package.Architecture}-${Package.PublicKeyToken}";
}

developer-library[libraw] {
    libraries : {
        libs
    };
}