[@bs.module "blockstack/lib/storage"]
external getFileDecrypted : string => Js.Promise.t(Js.nullable(string)) =
  "getFile";

[@bs.module "blockstack/lib/storage"]
external getFileNotDecrypted :
  (string, [@bs.as {json| {"decrypt": false} |json}] _) =>
  Js.Promise.t(Js.nullable(string)) =
  "getFile";

[@bs.module "blockstack/lib/storage"]
external getFileWithJsOpts :
  (string, Js.t({..})) => Js.Promise.t(Js.nullable(string)) =
  "getFile";

let getFileFromUser = (file, ~username, ~app) =>
  getFileWithJsOpts(
    file,
    {"username": username, "decrypt": false, "app": app},
  );

let getFileFromUserAndDecrypt = (file, ~username) =>
  getFileWithJsOpts(file, {"username": username, "decrypt": true});

[@bs.module "blockstack"]
external putFileEncrypted : (string, string) => Js.Promise.t(unit) =
  "putFile";

[@bs.module "blockstack"]
external _putFileEncryptedFor :
  (string, string, {. "encrypt": string}) => Js.Promise.t(unit) =
  "putFile";

let putFileEncryptedFor = (~path, ~content, ~pubKey) =>
  _putFileEncryptedFor(path, content, {"encrypt": pubKey});

[@bs.module "blockstack"]
external putFileNotEncrypted :
  (string, string, [@bs.as {json| {"encrypt": false} |json}] _) =>
  Js.Promise.t(unit) =
  "putFile";

[@bs.module "blockstack"]
external getUserAppFileUrl :
  (~path: string, ~username: string, ~appOrigin: string) =>
  Js.Promise.t(string) =
  "getUserAppFileUrl";

[@bs.module "blockstack/lib/keys.js"]
external makeECPrivateKey : unit => string = "makeECPrivateKey";

type profile;
[@bs.module "blockstack/lib/profiles"]
external lookupProfile : string => Js.Promise.t(profile) = "lookupProfile";

[@bs.module "blockstack/lib/encryption"]
external encryptECIES : (~publicKey: string, string) => Js.Json.t = "encryptECIES";
[@bs.module "blockstack/lib/encryption"]
external decryptECIES : (~privateKey: string, Js.Json.t) => string = "decryptECIES";
