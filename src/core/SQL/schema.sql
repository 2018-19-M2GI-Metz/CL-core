-- Base de données :  `libgps`

-- --------------------------------------------------------
-- Structure de la table `points`
-- [lecture seule]
-- Les segments représentent l'ensemble des points existants.

CREATE TABLE `point` (
    `id` INTEGER PRIMARY KEY,
    `name` varchar(191) NULL DEFAULT NULL,
    `address` varchar(191) NULL DEFAULT NULL,
    `latitude` double NOT NULL,
    `longitude` double NOT NULL
);

CREATE INDEX point_name_index ON point(name);

-- --------------------------------------------------------
-- Structure de la table `segments`
-- [lecture seule / écriture à l'initialisation]
-- Les segments représentent l'ensemble des routes existantes.

CREATE TABLE `segment` (
    `id` INTEGER PRIMARY KEY,
    `startPointId` INTEGER NOT NULL,
    `endPointId` INTEGER NOT NULL,
    `distance` INTEGER NOT NULL, -- in meter
    `time` INTEGER NOT NULL -- in second
);

-- --------------------------------------------------------
-- Structure de la table `path`
-- [lecture / écriture]
-- Les paths sont représentés par une liste de point consecutifs

CREATE TABLE `path` (
    `id` INTEGER PRIMARY KEY,
    `isShortest` INTEGER NOT NULL,
    `isFastest` INTEGER NOT NULL,
    `distance` INTEGER NOT NULL, -- in meter
    `time` INTEGER NOT NULL -- in second
);

-- --------------------------------------------------------
-- Structure de la table `pathpoints`
-- [lecture / écriture]
-- Représente un point indexé d'un path

CREATE TABLE `pathPoint` (
    `id` INTEGER PRIMARY KEY,
    `pathId` INTEGER NOT NULL,
    `pointId` INTEGER NOT NULL,
    `index` INTEGER NOT NULL
);
