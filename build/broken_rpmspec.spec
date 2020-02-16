#
# spec file for package EterniaLibrary (Using build.opensuse.org)
#   https://build.opensuse.org/package/show/home:EterniaLogic/EterniaLibrary

Name:           libeternia
Version:        1.122.6
Release:        1
License:        GPL-3.0 
Group:          Library 
Summary:        Bare-Bones C++11 Library for cross-platform use.
Prefix:         /usr
Url:            https://github.com/EterniaLogic/EterniaLibrary.git
Source:         ./
BuildRequires:  gcc 
BuildRequires:  gcc-c++
BuildRequires:  cmake 
Requires:       glibc
BuildRoot:      %{_tmppath}/%{name}-%{version}-build

%description 
EterniaLibrary, Bare-Bones C++11 Library for cross-platform use, commonly using libEternia.so, libEternia.dll.
Includes common Data structures, game logic, engineering baselines, Modding APIs, AI structures, simulation data and a Web Framework for RESTFul, HTTP, and sockets.

%prep 
#%setup -n EterniaLibrary-1.122.6


%install 
cd ~/rpmbuild/SOURCES/%{name}-%{version}
#./install
make install DESTDIR="$RPM_BUILD_ROOT"

%files 
%defattr(-,root,root,-)
%doc README.md LICENSE.txt CHANGELOG version.txt
%{_bindir}/*
%{_libdir}/*

%ifarch x86_64
%build 
cmake .
make Eternia
%endif

%ifarch i586
%build 
cmake .
make Eternia
%endif

%changelog 
