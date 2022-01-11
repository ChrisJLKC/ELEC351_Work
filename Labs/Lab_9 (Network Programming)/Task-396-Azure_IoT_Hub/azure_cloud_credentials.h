/*
 * Google Cloud Certificates
 * Copyright (c) 2019-2020, Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef AZURE_CLOUD_CREDENTIALS_H
#define AZURE_CLOUD_CREDENTIALS_H

namespace azure_cloud {
namespace credentials {
/*
 * Primary Connecion String
 */

// Use https://dpsgen.z8.web.core.windows.net/ to obtain YOUR connection string
// This one will not work, but I guess you knew that ;)
char iothub_connection_string[] = "HostName=iotc-7b8a73c0-de2a-4792-9c18-f252916e2fb3.azure-devices.net;DeviceId=jr39t6b3v5;SharedAccessKey=ELpWyioT6++V+6XEhQ86W0veM7XPfWB4xf1gB+6yXjM=";
}
}
#endif
