@import "version.inc";
@import "outercurve.inc";

package {
    name: "libraw[${flavor}]";
    version: "${package-version}";
    arch : "${arch}";
    
    display-name: "libraw";
    location: "http://coapp.org/repository/${OutputFilename}";

    feed: "http://coapp.org/repository/packages.atom.xml";
    publisher: "CoApp Project";
}

files[exes] {
    root: @"..\output\vc10\${arch}\release\bin";
    
    include: {
        "*.exe",
    };
    
    trim-path: all;
};


files[dlls] {
    root: @"..\output\vc10\${arch}\release\bin";
  
    include: {
        "*.dll",
    };
    
    trim-path: all;
};

license[LGPL] {
    license-url: "";
    license-type: "LGPL";
}

files[files-to-sign] {
    include: { 
        exes,
        dlls
    };    
}

metadata {
    summary: "libraw";
    description:  @"Library for reading and processing of RAW digicam images"; 

    icon: @"libraw.png";
    
    author-version : "0.14.5";
    bug-tracker: "https://github.com/coapp-packages/libraw/issues";
    stability : "0";
    licenses : {
        LGPL
    };
}

compatability-policy {
    minimum: "0.14.5.0";
    maximum: "${OneLessThanCurrent}"; // this is the default
    versions : {
        "0.14",
    }; // if not specified, find the versions by looking at the feeds and finding all the major/minor versions in range.
}

application {
    include : {
        exes,
    };
}

manifest[things-that-need-them] {
    // all of our EXEs need to get the manifest entries for the assemblies we're creating in this package
    
    assembly : {
        libraw
    };
    
    include : { 
        exes
    };
}

assembly[libraw] {
    include : {
        dlls
    };
}

package-composition {
    symlinks : { 
        exes => @"${bin}\${each.Name}" = @"${packagedir}\${each.Name}";
    };
}

signing {
    attributes : {
        company="Outercurve Foundation",
        description="libraw",
        product-name="libraw",
        product-version="${package-version}",
        file-version="${package-version}",
    };
    
    replace-signature: true; 
    include: { 
        files-to-sign
    };    
}