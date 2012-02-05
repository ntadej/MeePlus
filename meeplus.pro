#############################################################################
# MeePlus - Google+ client for Harmattan
# Copyright (C) 2011 Tadej Novak <tadej@tano.si>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>./
#############################################################################
# Configuration #
#################
# Defines
!isEmpty( GIT ) {
    DEFINES += GIT=$$GIT
}

!isEmpty( CLIENT_ID ) {
    DEFINES += CLIENT_ID=\\\"$$CLIENT_ID\\\"
} else {
    error("Please set CLIENT_ID!")
}

!isEmpty( CLIENT_SECRET ) {
    DEFINES += CLIENT_SECRET=\\\"$$CLIENT_SECRET\\\"
} else {
    error("Please set CLIENT_SECRET!")
}

# Include all subdirectories
INCLUDEPATH += src \
    src/core \
    src/json \
    src/activities/handlers \
    src/activities/items \
    src/activities/models \
    src/people/handlers \
    src/people/items \
    src/people/models

# Add more folders to ship with the application, here
qml_deploy.source = src/qml
qml_deploy.target =
DEPLOYMENTFOLDERS = qml_deploy

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

symbian:TARGET.UID3 = 0xE86D2774

# Smart Installer package's UID
# This UID is from the protected range and therefore the package will
# fail to install if self-signed. By default qmake uses the unprotected
# range value if unprotected UID is defined for the application and
# 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# Add Qt modules
QT += network

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# Speed up launching on MeeGo/Harmattan when using applauncherd daemon
CONFIG += qdeclarative-boostable

# Add dependency to symbian components
# CONFIG += qtquickcomponents


###########
# Sources #
###########
# Core
SOURCES += src/main.cpp \
    src/Application.cpp \
    src/core/Authentication.cpp \
    src/core/Common.cpp \
    src/core/Constants.cpp \
    src/core/ListModel.cpp \
    src/core/LocaleManager.cpp  \
    src/core/NetworkRequest.cpp \
    src/core/PageStack.cpp \
    src/core/Settings.cpp \
    src/core/Translations.cpp

# Json
SOURCES += \
    src/json/json.cpp

# Activities
SOURCES += \
    src/activities/handlers/ActivitiesHandler.cpp \
    src/activities/items/Activity.cpp \
    src/activities/models/ActivitiesFilterModel.cpp \
    src/activities/models/ActivitiesModel.cpp

# People
SOURCES += \
    src/people/handlers/PeopleHandler.cpp \
    src/people/items/Person.cpp \
    src/people/items/PersonInformation.cpp \
    src/people/items/PersonOrganization.cpp \
    src/people/models/PeopleEmailsFilterModel.cpp \
    src/people/models/PeopleFilterModel.cpp \
    src/people/models/PeopleInformationModel.cpp \
    src/people/models/PeopleLanguagesFilterModel.cpp \
    src/people/models/PeopleModel.cpp \
    src/people/models/PeopleOrganizationsFilterModel.cpp \
    src/people/models/PeopleOrganizationsModel.cpp \
    src/people/models/PeoplePlacesFilterModel.cpp \
    src/people/models/PeopleUrlsFilterModel.cpp


###########
# Headers #
###########
# Core
HEADERS += \
    src/Application.h \
    src/core/Authentication.h \
    src/core/Common.h \
    src/core/Config.h \
    src/core/Constants.h \
    src/core/ListItem.h \
    src/core/ListModel.h \
    src/core/LocaleManager.h  \
    src/core/NetworkRequest.h \
    src/core/PageStack.h \
    src/core/Settings.h \
    src/core/Translations.h \
    src/core/Enums.h

# Activities
HEADERS += \
    src/activities/handlers/ActivitiesHandler.h \
    src/activities/items/Activity.h \
    src/activities/models/ActivitiesFilterModel.h \
    src/activities/models/ActivitiesModel.h

# People
HEADERS += \
    src/people/handlers/PeopleHandler.h \
    src/people/items/Person.h \
    src/people/items/PersonInformation.h \
    src/people/items/PersonOrganization.h \
    src/people/models/PeopleEmailsFilterModel.h \
    src/people/models/PeopleFilterModel.h \
    src/people/models/PeopleInformationModel.h \
    src/people/models/PeopleLanguagesFilterModel.h \
    src/people/models/PeopleModel.h \
    src/people/models/PeopleOrganizationsFilterModel.h \
    src/people/models/PeopleOrganizationsModel.h \
    src/people/models/PeoplePlacesFilterModel.h \
    src/people/models/PeopleUrlsFilterModel.h


##############
# Deployment #
##############
# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

OTHER_FILES += api.txt \
    LICENSE.GPL \
    NEWS \
    README \
    VERSION \

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog








