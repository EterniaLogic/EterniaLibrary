#
# spec file for package EterniaLibrary (Using build.opensuse.org)
#   https://build.opensuse.org/package/show/home:EterniaLogic/EterniaLibrary

Name:           EterniaLibrary
Version:        0.1.0 
Release:        1
License:        GPL-3.0 
Group:          Library 
Summary:        Bare-Bones C++11 Library for cross-platform use.
Url:            https://github.com/EterniaLogic/EterniaLibrary.git
Source:         eternialibrary-%{version}.tar.gz 
BuildRequires:  gcc 
BuildRequires:  cmake 
BuildRoot:      .

%description 
Bare-Bones C++11 Library for cross-platform use, commonly using libEternia.so, libEternia.dll.
Includes common Data structures, game logic, engineering baselines, Modding APIs, AI structures, simulation data and a Web Framework for RESTFul, HTTP, and sockets.

%prep 
%setup -q -n %{name}-%{version}

%build 
cmake .
make -j8

%install 
./install

%files 
%defattr(-,root,root,-)
%doc README LICENSE *.txt
%{_bindir}/*

%changelog 